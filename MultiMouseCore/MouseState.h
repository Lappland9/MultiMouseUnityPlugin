#pragma once

#include <Windows.h>

enum class MouseRole
{
    Left,
    Right
};

struct MouseState
{
    HANDLE device = nullptr;

    LONG deltaX = 0;
    LONG deltaY = 0;

    // 現在押されているか
    bool leftButtonDown = false;
    bool rightButtonDown = false;

    // 今回のフレームで押されたか
    bool leftButtonPressed = false;
    bool rightButtonPressed = false;

    // 今回のフレームで離されたか
    bool leftButtonReleased = false;
    bool rightButtonReleased = false;
};