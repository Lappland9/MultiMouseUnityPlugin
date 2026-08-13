#pragma once

extern "C"
{
    bool MultiMouseCore_Initialize();

    void MultiMouseCore_Shutdown();

    void MultiMouseCore_Update();

    void MultiMouseCore_StartLeftPairing();
    void MultiMouseCore_StartRightPairing();

    int MultiMouseCore_GetLeftDeltaX();
    int MultiMouseCore_GetLeftDeltaY();

    int MultiMouseCore_GetRightDeltaX();
    int MultiMouseCore_GetRightDeltaY();

    bool MultiMouseCore_IsLeftAssigned();
    bool MultiMouseCore_IsRightAssigned();

    bool MultiMouseCore_GetLeftButtonDown();
    bool MultiMouseCore_GetLeftButtonPressed();
    bool MultiMouseCore_GetLeftButtonReleased();

    bool MultiMouseCore_GetRightButtonDown();
    bool MultiMouseCore_GetRightButtonPressed();
    bool MultiMouseCore_GetRightButtonReleased();

    bool MultiMouseCore_GetLeftRightButtonDown();
    bool MultiMouseCore_GetLeftRightButtonPressed();
    bool MultiMouseCore_GetLeftRightButtonReleased();

    bool MultiMouseCore_GetRightRightButtonDown();
    bool MultiMouseCore_GetRightRightButtonPressed();
    bool MultiMouseCore_GetRightRightButtonReleased();
}