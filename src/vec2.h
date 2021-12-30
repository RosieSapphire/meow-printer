#ifndef VEC2_H
#define VEC2_H

#include <cmath>

template <typename T>
struct vec2 {
    T x;
    T y;

    vec2() = default;
    constexpr vec2(const T &x, const T &y): x(x), y(y) {}
    constexpr vec2(const T &both): x(both), y(both) {}

    template <typename U>
    explicit vec2(const vec2<U> &vec): x(static_cast<T>(vec.x)), y(static_cast<T>(vec.y)) {}

    constexpr vec2 operator+(const vec2 &other) const {
        return {x + other.x, y + other.y};
    }

    vec2& operator+=(const vec2 &other) {
        return *this = *this + other;
    }

    constexpr vec2 operator-(const vec2 &other) const {
        return {x - other.x, y - other.y};
    }

    vec2& operator-=(const vec2 &other) {
        return *this = *this - other;
    }

    constexpr vec2 operator*(const T &other) const {
        return {x * other, y * other};
    }

    vec2& operator*=(const float &other) {
        return *this = *this * other;
    }

    constexpr float get_mag_sq() const {
        return x * x + y * y;
    }

    constexpr float get_mag() const {
        return sqrtf(get_mag_sq());
    }

    constexpr vec2 get_normalized() const {
        return *this * (1.0f / (get_mag() > 0.0f ? get_mag() : 1.0f));
    }

    vec2& normalize() {
        return *this = *this * (1.0f / (get_mag() > 0.0f ? get_mag() : 1.0f));
    }
};

#endif