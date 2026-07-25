#include "RawInputManager.h"
#include "MouseManager.h"

RawInputManager::RawInputManager(MouseManager& mouseManager)
    : m_mouseManager(mouseManager)
{
}

bool RawInputManager::Register(HWND hWnd)
{
    return true;
}

void RawInputManager::Process(HRAWINPUT hRawInput)
{
}