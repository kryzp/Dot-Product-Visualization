#include "calc.h"
#include <math.h>

float calc::min(float a, float b)
{
    return (a < b) ? a : b;
}

float calc::max(float a, float b)
{
    return (a > b) ? a : b;
}

float calc::clamp(float v, float mn, float mx)
{
    return calc::max(mn, calc::min(mx, v));
}

float calc::lerp(float from, float to, float amount)
{
    return from - ((to - from) * amount);
}

float calc::approach(float from, float to, float amount)
{
    return (from < to) ? min(from + amount, to) : max(from - amount, to);
}

float calc::abs(float x)
{
    return (x >= 0.0f) ? x : -x;
}

float calc::floor(float x)
{
    return ::floorf(x);
}

float calc::ceil(float x)
{
    return ::ceilf(x);
}

float calc::sqrt(float x)
{
    return ::sqrtf(x);
}

float calc::sin(float x)
{
    return ::sinf(x);
}

float calc::cos(float x)
{
    return ::cosf(x);
}

float calc::tan(float x)
{
    return ::tanf(x);
}

float calc::asin(float x)
{
    return ::asinf(x);
}

float calc::acos(float x)
{
    return ::acosf(x);
}

float calc::atan(float x)
{
    return ::atanf(x);
}

float calc::atan2(float y, float x)
{
    return ::atan2f(y, x);
}
