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
};