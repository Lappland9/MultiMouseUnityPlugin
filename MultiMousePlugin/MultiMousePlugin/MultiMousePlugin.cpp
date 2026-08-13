#include "pch.h"

#include "MultiMousePlugin.h"
#include "MultiMouseCore.h"

int __cdecl MultiMouse_Initialize()
{
    return MultiMouseCore_Initialize() ? 1 : 0;
}

void __cdecl MultiMouse_Shutdown()
{
    MultiMouseCore_Shutdown();
}

void __cdecl MultiMouse_Update()
{
    MultiMouseCore_Update();
}


// ========================================
// Pairing
// ========================================

void __cdecl MultiMouse_StartLeftPairing()
{
    MultiMouseCore_StartLeftPairing();
}

void __cdecl MultiMouse_StartRightPairing()
{
    MultiMouseCore_StartRightPairing();
}

int __cdecl MultiMouse_IsLeftAssigned()
{
    return MultiMouseCore_IsLeftAssigned() ? 1 : 0;
}

int __cdecl MultiMouse_IsRightAssigned()
{
    return MultiMouseCore_IsRightAssigned() ? 1 : 0;
}


// ========================================
// Movement
// ========================================

int __cdecl MultiMouse_GetLeftDeltaX()
{
    return MultiMouseCore_GetLeftDeltaX();
}

int __cdecl MultiMouse_GetLeftDeltaY()
{
    return MultiMouseCore_GetLeftDeltaY();
}

int __cdecl MultiMouse_GetRightDeltaX()
{
    return MultiMouseCore_GetRightDeltaX();
}

int __cdecl MultiMouse_GetRightDeltaY()
{
    return MultiMouseCore_GetRightDeltaY();
}

// ========================================
// Left-hand mouse : Left button
// ========================================

int __cdecl MultiMouse_GetLeftButtonDown()
{
    return MultiMouseCore_GetLeftButtonDown() ? 1 : 0;
}

int __cdecl MultiMouse_GetLeftButtonPressed()
{
    return MultiMouseCore_GetLeftButtonPressed() ? 1 : 0;
}

int __cdecl MultiMouse_GetLeftButtonReleased()
{
    return MultiMouseCore_GetLeftButtonReleased() ? 1 : 0;
}


// ========================================
// Right-hand mouse : Left button
// ========================================

int __cdecl MultiMouse_GetRightButtonDown()
{
    return MultiMouseCore_GetRightButtonDown() ? 1 : 0;
}

int __cdecl MultiMouse_GetRightButtonPressed()
{
    return MultiMouseCore_GetRightButtonPressed() ? 1 : 0;
}

int __cdecl MultiMouse_GetRightButtonReleased()
{
    return MultiMouseCore_GetRightButtonReleased() ? 1 : 0;
}


// ========================================
// Left-hand mouse : Right button
// ========================================

int __cdecl MultiMouse_GetLeftRightButtonDown()
{
    return MultiMouseCore_GetLeftRightButtonDown() ? 1 : 0;
}

int __cdecl MultiMouse_GetLeftRightButtonPressed()
{
    return MultiMouseCore_GetLeftRightButtonPressed() ? 1 : 0;
}

int __cdecl MultiMouse_GetLeftRightButtonReleased()
{
    return MultiMouseCore_GetLeftRightButtonReleased() ? 1 : 0;
}


// ========================================
// Right-hand mouse : Right button
// ========================================

int __cdecl MultiMouse_GetRightRightButtonDown()
{
    return MultiMouseCore_GetRightRightButtonDown() ? 1 : 0;
}

int __cdecl MultiMouse_GetRightRightButtonPressed()
{
    return MultiMouseCore_GetRightRightButtonPressed() ? 1 : 0;
}

int __cdecl MultiMouse_GetRightRightButtonReleased()
{
    return MultiMouseCore_GetRightRightButtonReleased() ? 1 : 0;
}