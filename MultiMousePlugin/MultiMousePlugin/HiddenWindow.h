#pragma once

#include <Windows.h>

class HiddenWindow
{
public:

    HiddenWindow();

    ~HiddenWindow();

    bool Create();

    void Destroy();

    HWND GetHandle() const;

private:

    HWND m_hWnd = nullptr;

    static LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam);
};