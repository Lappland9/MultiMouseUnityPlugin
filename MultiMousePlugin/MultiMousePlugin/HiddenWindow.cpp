#include "HiddenWindow.h"

HiddenWindow::HiddenWindow()
{
}

HiddenWindow::~HiddenWindow()
{
    Destroy();
}

bool HiddenWindow::Create()
{
    return true;
}

void HiddenWindow::Destroy()
{
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