#include "pch.h"
#include "RawInputManager.h"
#include "MouseManager.h"
#include <Windows.h>
#include <iostream>
#include <vector>

RawInputManager::RawInputManager(MouseManager& mouseManager)
    : m_mouseManager(mouseManager)
{
}

bool RawInputManager::Register(HWND hWnd)
{
    RAWINPUTDEVICE device{};

    // Generic Desktop Controls
    device.usUsagePage = 0x01;

    // Mouse
    device.usUsage = 0x02;

    // バックグラウンドでも受信する
    device.dwFlags = RIDEV_INPUTSINK;

    // 送り先
    device.hwndTarget = hWnd;

    if (!RegisterRawInputDevices(
        &device,
        1,
        sizeof(RAWINPUTDEVICE)))
    {
        return false;
    }

    return true;
}

void RawInputManager::ProcessInput(LPARAM lParam)
{
    UINT size = 0;

    if (GetRawInputData(
        reinterpret_cast<HRAWINPUT>(lParam),
        RID_INPUT,
        nullptr,
        &size,
        sizeof(RAWINPUTHEADER)) == static_cast<UINT>(-1))
    {
        return;
    }

    if (size == 0)
    {
        return;
    }

    std::vector<BYTE> buffer(size);

    if (GetRawInputData(
        reinterpret_cast<HRAWINPUT>(lParam),
        RID_INPUT,
        buffer.data(),
        &size,
        sizeof(RAWINPUTHEADER)) != size)
    {
        return;
    }

    RAWINPUT* raw =
        reinterpret_cast<RAWINPUT*>(buffer.data());

    if (raw->header.dwType == RIM_TYPEMOUSE)
    {
        m_mouseManager.UpdateMouse(
            raw->header.hDevice,
            raw->data.mouse.lLastX,
            raw->data.mouse.lLastY,
            raw->data.mouse.usButtonFlags);
    }
}

void RawInputManager::Unregister()
{
    RAWINPUTDEVICE device{};

    device.usUsagePage = 0x01;
    device.usUsage = 0x02;

    device.dwFlags = RIDEV_REMOVE;

    // RIDEV_REMOVEの場合はnullptr必須
    device.hwndTarget = nullptr;

    RegisterRawInputDevices(
        &device,
        1,
        sizeof(RAWINPUTDEVICE));
}