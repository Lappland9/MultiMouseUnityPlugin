#include "MouseManager.h"

MouseManager::MouseManager()
{
}

MouseState& MouseManager::GetMouse(std::size_t index)
{
    return m_mice.at(index);
}

const MouseState& MouseManager::GetMouse(std::size_t index) const
{
    return m_mice.at(index);
}