#include "pch.h"

#include "MultiMouseCore.h"

#include "HiddenWindow.h"
#include "RawInputManager.h"
#include "MouseManager.h"

namespace
{
    MouseManager* g_mouseManager = nullptr;
    RawInputManager* g_rawInputManager = nullptr;
    HiddenWindow* g_hiddenWindow = nullptr;
}

int MultiMouseCore_GetLeftDeltaX()
{
    if (g_mouseManager == nullptr)
    {
        return 0;
    }

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
    {
        return 0;
    }

    return static_cast<int>(mouse->deltaX);
}

int MultiMouseCore_GetLeftDeltaY()
{
    if (g_mouseManager == nullptr)
    {
        return 0;
    }

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
    {
        return 0;
    }

    return static_cast<int>(mouse->deltaY);
}

int MultiMouseCore_GetRightDeltaX()
{
    if (g_mouseManager == nullptr)
    {
        return 0;
    }

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
    {
        return 0;
    }

    return static_cast<int>(mouse->deltaX);
}

int MultiMouseCore_GetRightDeltaY()
{
    if (g_mouseManager == nullptr)
    {
        return 0;
    }

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
    {
        return 0;
    }

    return static_cast<int>(mouse->deltaY);
}

// ========================================
// Left-hand mouse : Left button
// ========================================

bool MultiMouseCore_GetLeftButtonDown()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
        return false;

    return mouse->leftButtonDown;
}

bool MultiMouseCore_GetLeftButtonPressed()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
        return false;

    return mouse->leftButtonPressed;
}

bool MultiMouseCore_GetLeftButtonReleased()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
        return false;

    return mouse->leftButtonReleased;
}


// ========================================
// Right-hand mouse : Left button
// ========================================

bool MultiMouseCore_GetRightButtonDown()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
        return false;

    return mouse->leftButtonDown;
}

bool MultiMouseCore_GetRightButtonPressed()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
        return false;

    return mouse->leftButtonPressed;
}

bool MultiMouseCore_GetRightButtonReleased()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
        return false;

    return mouse->leftButtonReleased;
}


// ========================================
// Left-hand mouse : Right button
// ========================================

bool MultiMouseCore_GetLeftRightButtonDown()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
        return false;

    return mouse->rightButtonDown;
}

bool MultiMouseCore_GetLeftRightButtonPressed()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
        return false;

    return mouse->rightButtonPressed;
}

bool MultiMouseCore_GetLeftRightButtonReleased()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Left);

    if (mouse == nullptr)
        return false;

    return mouse->rightButtonReleased;
}


// ========================================
// Right-hand mouse : Right button
// ========================================

bool MultiMouseCore_GetRightRightButtonDown()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
        return false;

    return mouse->rightButtonDown;
}

bool MultiMouseCore_GetRightRightButtonPressed()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
        return false;

    return mouse->rightButtonPressed;
}

bool MultiMouseCore_GetRightRightButtonReleased()
{
    if (g_mouseManager == nullptr)
        return false;

    const MouseState* mouse =
        g_mouseManager->GetMouse(MouseRole::Right);

    if (mouse == nullptr)
        return false;

    return mouse->rightButtonReleased;
}

bool MultiMouseCore_IsLeftAssigned()
{
    if (g_mouseManager == nullptr)
    {
        return false;
    }

    return g_mouseManager->IsLeftAssigned();
}

bool MultiMouseCore_IsRightAssigned()
{
    if (g_mouseManager == nullptr)
    {
        return false;
    }

    return g_mouseManager->IsRightAssigned();
}

bool MultiMouseCore_Initialize()
{
    if (g_mouseManager != nullptr)
    {
        return true;
    }

    g_mouseManager = new MouseManager();

    g_rawInputManager =
        new RawInputManager(*g_mouseManager);

    g_hiddenWindow =
        new HiddenWindow(*g_rawInputManager);

    if (!g_hiddenWindow->Create())
    {
        delete g_hiddenWindow;
        delete g_rawInputManager;
        delete g_mouseManager;

        g_hiddenWindow = nullptr;
        g_rawInputManager = nullptr;
        g_mouseManager = nullptr;

        return false;
    }

    return true;
}

void MultiMouseCore_Shutdown()
{
    if (g_rawInputManager != nullptr)
    {
        g_rawInputManager->Unregister();
    }

    delete g_hiddenWindow;
    delete g_rawInputManager;
    delete g_mouseManager;

    g_hiddenWindow = nullptr;
    g_rawInputManager = nullptr;
    g_mouseManager = nullptr;
}

void MultiMouseCore_StartLeftPairing()
{
    if (g_mouseManager != nullptr)
    {
        g_mouseManager->StartLeftPairing();
    }
}

void MultiMouseCore_StartRightPairing()
{
    if (g_mouseManager != nullptr)
    {
        g_mouseManager->StartRightPairing();
    }
}

void MultiMouseCore_Update()
{
    if (g_hiddenWindow == nullptr)
    {
        return;
    }

    if (g_mouseManager != nullptr)
    {
        g_mouseManager->BeginFrame();
    }

    MSG msg{};

    HWND hwnd = g_hiddenWindow->GetHandle();

    while (PeekMessageW(
        &msg,
        hwnd,
        0,
        0,
        PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}