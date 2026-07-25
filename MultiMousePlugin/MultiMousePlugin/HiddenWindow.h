#pragma once

#include <Windows.h>

class RawInputManager;

class HiddenWindow
{
public:

    explicit HiddenWindow(RawInputManager& rawInputManager);

    ~HiddenWindow();

    bool Create();

    void Destroy();

    HWND GetHandle() const;

private:

    HWND m_hWnd = nullptr;

    RawInputManager& m_rawInputManager;

    static LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam);
};