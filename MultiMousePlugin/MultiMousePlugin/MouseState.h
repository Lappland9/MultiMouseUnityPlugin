#include <cstdint>

struct MouseState
{
    bool connected = false;

    std::int32_t deltaX = 0;
    std::int32_t deltaY = 0;

    std::int32_t wheelDelta = 0;

    bool leftButton = false;
    bool rightButton = false;
    bool middleButton = false;
};