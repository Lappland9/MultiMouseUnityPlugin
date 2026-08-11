#include "pch.h"

#include "HiddenWindow.h"
#include "RawInputManager.h"

HiddenWindow::HiddenWindow(RawInputManager& rawInputManager)
    : m_rawInputManager(rawInputManager)
{
}

HiddenWindow::~HiddenWindow()
{
    Destroy();
}

bool HiddenWindow::Create()
{
    WNDCLASSEXW wc{};

    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.lpfnWndProc = HiddenWindow::WindowProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = L"MultiMouseHiddenWindow";

    if (!RegisterClassExW(&wc))
    {
        return false;
    }

    m_hWnd = CreateWindowExW(
        0,
        L"MultiMouseHiddenWindow",
        L"",
        0,
        0,
        0,
        0,
        0,
        HWND_MESSAGE,
        nullptr,
        GetModuleHandleW(nullptr),
        nullptr);

    if (m_hWnd == nullptr)
    {
        return false;
    }

    return true;
}

void HiddenWindow::Destroy()
{
    if (m_hWnd != nullptr)
    {
        DestroyWindow(m_hWnd);
        m_hWnd = nullptr;
    }
}

HWND HiddenWindow::GetHandle() const
{
    return m_hWnd;
}

LRESULT CALLBACK HiddenWindow::WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam)
{
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}