#pragma once

namespace calc
{
    constexpr float PI = 3.14159265359f;
    constexpr float TAU = PI * 2.0f;
    constexpr float RAD2DEG = 180.0f / PI;
    constexpr float DEG2RAD = PI / 180.0f;

    float min(float a, float b);
    float max(float a, float b);
    float clamp(float v, float mn, float mx);

    float lerp(float from, float to, float amount);
    float approach(float from, float to, float amount);

    float abs(float x);
    float floor(float x);
    float ceil(float x);

    float sqrt(float x);

    float sin(float x);
    float cos(float x);
    float tan(float x);
    
    float asin(float x);
    float acos(float x);
    float atan(float x);
    float atan2(float y, float x);
}
