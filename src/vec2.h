#pragma once

#include <SFML/Graphics.hpp>
#include <ostream>

#include "calc.h"

namespace math
{
    template <typename T>
    struct Vec2
    {
        const static Vec2<T> ZERO;
        const static Vec2<T> ONE;
        const static Vec2<T> UP;
        const static Vec2<T> DOWN;
        const static Vec2<T> LEFT;
        const static Vec2<T> RIGHT;

        T x;
        T y;

        Vec2()
            : x(0)
            , y(0)
        {
        }

        Vec2(T x)
            : x(x)
            , y(x)
        {
        }

        Vec2(T x, T y)
            : x(x)
            , y(y)
        {
        }

        float length() const
        {
            return sqrt(length_squared());
        }

        float length_squared() const
        {
            return (x * x) + (y * y);
        }

        Vec2 normal() const
        {
            if (x == 0 && y == 0)
                return Vec2::ZERO;

            float len = length();
            return Vec2(x / len, y / len);
        }

        Vec2 perpendicular() const
        {
            return Vec2(-y, x);
        }

        Vec2 abs() const
        {
            return Vec2(abs(x), abs(y));
        }

        Vec2 ceil() const
        {
            return Vec2(ceil(x), ceil(y));
        }
        
        Vec2 floor() const
        {
            return Vec2(floor(x), floor(y));
        }

        float angle() const
        {
            return atan2(y, x);
        }

        void rotate(float amount)
        {
            float cs = cos(amount);
            float sn = sin(amount);

            float px = x * cs - y * sn; 
            float py = x * sn + y * cs;

            this->x = px;
            this->y = py;
        }

        static T dot(const Vec2& a, const Vec2& b)
        {
            return (a.x * b.x) + (a.y * b.y);
        }

        static Vec2 from_angle(float radians, float length)
        {
            return Vec2(
                static_cast<float>(cos(radians) * length),
                static_cast<float>(sin(radians) * length)
            );
        }

        sf::Vector2<T> to_sfml() const { return sf::Vector2<T>(x, y); }

        Vec2 operator  +  (const Vec2& other) const { return Vec2( this->x + other.x,  this->y + other.y); }
        Vec2 operator  -  (const Vec2& other) const { return Vec2( this->x - other.x,  this->y - other.y); }
        Vec2 operator  -  ()                  const { return Vec2(-this->x,           -this->y          ); }
        Vec2 operator  *  (const Vec2& other) const { return Vec2( this->x * other.x,  this->y * other.y); }
        Vec2 operator  *  (float value)       const { return Vec2( this->x * value,    this->y * value  ); }
        Vec2 operator  /  (const Vec2& other) const { return Vec2( this->x / other.x,  this->y / other.y); }

        Vec2& operator += (const Vec2& other)       { this->x += other.x; this->y += other.y; return *this; }
        Vec2& operator -= (const Vec2& other)       { this->x -= other.x; this->y -= other.y; return *this; }
        Vec2& operator *= (const Vec2& other)       { this->x *= other.x; this->y *= other.y; return *this; }
        Vec2& operator *= (float value)             { this->x *= value;   this->y *= value;   return *this; }
        Vec2& operator /= (const Vec2& other)       { this->x /= other.x; this->y /= other.y; return *this; }

        bool operator ==  (const Vec2& other)       { return (this->x == other.x) && (this->y == other.y); }
        bool operator !=  (const Vec2& other)       { return !(*this == other); }

        friend std::ostream& operator << (std::ostream& os, const Vec2& vec)
        {
            os << "{ " << vec.x << ", " << vec.y << " }";
            return os;
        }
    };

    template <typename T> const Vec2<T> Vec2<T>::ZERO  = Vec2<T>( 0,  0);
    template <typename T> const Vec2<T> Vec2<T>::ONE   = Vec2<T>( 1,  1);
    template <typename T> const Vec2<T> Vec2<T>::UP    = Vec2<T>( 0, -1);
    template <typename T> const Vec2<T> Vec2<T>::DOWN  = Vec2<T>( 0,  1);
    template <typename T> const Vec2<T> Vec2<T>::LEFT  = Vec2<T>(-1,  0);
    template <typename T> const Vec2<T> Vec2<T>::RIGHT = Vec2<T>( 1,  0);

    using Vec2I = Vec2<int>;
    using Vec2F = Vec2<float>;
}
