#include "pch.h"

#include "MouseManager.h"

void MouseManager::BeginFrame()
{
    for (int i = 0; i < m_mouseCount; ++i)
    {
        m_mice[i].deltaX = 0;
        m_mice[i].deltaY = 0;
    }
}

void MouseManager::UpdateMouse(
    HANDLE device,
    LONG deltaX,
    LONG deltaY)
{
    // 左手用マウスのペアリング中
    if (m_pairingLeft)
    {
        if (AssignLeftMouse(device))
        {
            m_pairingLeft = false;
        }
    }

    // 右手用マウスのペアリング中
    if (m_pairingRight)
    {
        if (AssignRightMouse(device))
        {
            m_pairingRight = false;
        }
    }

    // 既に登録されているマウスなら移動量を更新
    for (int i = 0; i < m_mouseCount; ++i)
    {
        if (m_mice[i].device == device)
        {
            m_mice[i].deltaX += deltaX;
            m_mice[i].deltaY += deltaY;
            return;
        }
    }

    // 新しいマウスなら登録
    if (m_mouseCount < MaxMouseCount)
    {
        m_mice[m_mouseCount].device = device;
        m_mice[m_mouseCount].deltaX = deltaX;
        m_mice[m_mouseCount].deltaY = deltaY;

        ++m_mouseCount;
    }
}

const MouseState* MouseManager::GetMouse(MouseRole role) const
{
    HANDLE targetDevice = nullptr;

    if (role == MouseRole::Left)
    {
        targetDevice = m_leftDevice;
    }
    else if (role == MouseRole::Right)
    {
        targetDevice = m_rightDevice;
    }

    if (targetDevice == nullptr)
    {
        return nullptr;
    }

    for (int i = 0; i < m_mouseCount; ++i)
    {
        if (m_mice[i].device == targetDevice)
        {
            return &m_mice[i];
        }
    }

    return nullptr;
}

bool MouseManager::AssignLeftMouse(HANDLE device)
{
    if (device == nullptr)
    {
        return false;
    }

    if (device == m_rightDevice)
    {
        return false;
    }

    m_leftDevice = device;

    return true;
}

bool MouseManager::AssignRightMouse(HANDLE device)
{
    if (device == nullptr)
    {
        return false;
    }

    if (device == m_leftDevice)
    {
        return false;
    }

    m_rightDevice = device;

    return true;
}

void MouseManager::StartLeftPairing()
{
    m_pairingLeft = true;
    m_pairingRight = false;
}

void MouseManager::StartRightPairing()
{
    m_pairingLeft = false;
    m_pairingRight = true;
}

bool MouseManager::IsLeftAssigned() const
{
    return m_leftDevice != nullptr;
}

bool MouseManager::IsRightAssigned() const
{
    return m_rightDevice != nullptr;
}