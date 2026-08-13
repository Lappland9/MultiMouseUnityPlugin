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