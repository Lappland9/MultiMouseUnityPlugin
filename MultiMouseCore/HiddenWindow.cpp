#include "pch.h"
#include "HiddenWindow.h"

HiddenWindow::HiddenWindow(RawInputManager& rawInputManager): m_rawInputManager(rawInputManager)
{
}

HiddenWindow::~HiddenWindow()
{
    Destroy();
}

bool HiddenWindow::Create()
{
    WNDCLASSEX wc{};

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = HiddenWindow::WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = L"MultiMouseHiddenWindow";

    if (!RegisterClassEx(&wc))
    {
        return false;
    }

    m_hWnd = CreateWindowEx(
        0,
        L"MultiMouseHiddenWindow",
        L"",
        0,
        0,
        0,
        0,
        0,
        nullptr,
        nullptr,
        GetModuleHandle(nullptr),
        nullptr);

    if (m_hWnd == nullptr)
    {
        return false;
    }

    return true;
}

void HiddenWindow::Destroy()
{
    if (m_hWnd)
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
    return DefWindowProc(hwnd, msg, wParam, lParam);
}