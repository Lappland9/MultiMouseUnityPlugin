#pragma once

#include <array>
#include "MouseState.h"

class MouseManager
{
public:

    static constexpr std::size_t MaxMouseCount = 4;

    MouseManager();

    MouseState& GetMouse(std::size_t index);

    const MouseState& GetMouse(std::size_t index) const;

private:

    std::array<MouseState, MaxMouseCount> m_mice;
};
