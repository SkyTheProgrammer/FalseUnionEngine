//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Math/Vector2.h"

#include <cmath>


Vector2::Vector2()
{
    x=0;
    y=0;
}

Vector2::Vector2(float newX, float newY) {
    x = newX;
    y = newY;
}

Vector2 Vector2::operator+(const Vector2 &rhs) const {
    return {this->x + rhs.x, this->y + rhs.y};
}

Vector2 Vector2::operator-(const Vector2 &rhs) const {
    return {this->x - rhs.x, this->y - rhs.y};
}

Vector2 Vector2::operator*(float rhs) const {
    return {this->x * rhs, this->y * rhs};
}

Vector2 Vector2::operator/(float rhs) const {
    return {this->x / rhs, this->y / rhs};
}

float Vector2::length() const {
    return std::sqrt(this->x * this->x + this->y * this->y);
}

Vector2 Vector2::normalize() const {
    return {this->x / length(), this->y / length()};
}

float Vector2::dot(const Vector2 &rhs) const {
    return this->x * rhs.x + this->y * rhs.y;
}

void Vector2::setVector2(const float newX, const float newY) {
    x = newX;
    y = newY;
}
