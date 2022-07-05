#include "PlayerMovers.h"

float leftVelocity(float &xVel, int minCap) {
    if (xVel > minCap)
    {
        xVel -= 5;
    }
    else
    {
        return 0;
    }
}

float rightVelocity(float &xVel, int maxCap, int plrWidth) {
    if (xVel < (maxCap-plrWidth))
    {
        xVel += 5;
    }
    else
    {
        return 0;
    }
}