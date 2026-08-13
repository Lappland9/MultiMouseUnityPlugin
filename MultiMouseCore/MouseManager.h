#pragma once

#include "MouseState.h"

class MouseManager
{
public:
    void BeginFrame();

    void UpdateMouse(
        HANDLE device,
        LONG deltaX,
        LONG deltaY,
        USHORT buttonFlags);

    const MouseState* GetMouse(int index) const;

    const MouseState* GetMouse(MouseRole role) const;

    bool AssignLeftMouse(HANDLE device);
    bool AssignRightMouse(HANDLE device);

    void StartLeftPairing();
    void StartRightPairing();

    bool IsLeftAssigned() const;
    bool IsRightAssigned() const;

private:
    static constexpr int MaxMouseCount = 2;

    MouseState m_mice[MaxMouseCount];

    int m_mouseCount = 0;

    HANDLE m_leftDevice = nullptr;
    HANDLE m_rightDevice = nullptr;

    bool m_pairingLeft = false;
    bool m_pairingRight = false;
};