//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

namespace FalseUnion
{
    class Vector2
    {
    public:
        Vector2(); // default constructor
        Vector2(float newX, float newY); //Constructor with existing values
        ~Vector2(); //Deconstructor for Vector2
        Vector2 operator+(const Vector2& rhs) const; //modification to Vector2 + operator
        Vector2 operator-(const Vector2& rhs) const; //modification to Vector2 - operator
        Vector2 operator*(float rhs) const; //modification to Vector2 * operator
        Vector2 operator/(float rhs) const; //modification to Vector2 / operator
        float length() const; //Length method of Vector2
        Vector2 normalize() const; //Normalize method of Vector2
        float dot(const Vector2& rhs) const; //dot method of Vector2
        void setVector2(float newX, float newY); //the Set Function of Vector2 based on float
        void setVector2(const Vector2& rhs); //the Set Function of Vector2 based on Vector2
        void setX(float newX); //setX method of Vector2 based on float
        void setY(float newY); //setY method of Vector2 based on float
        void setX(const Vector2& rhs); //setX method of Vector2 based on Vector2
        void setY(const Vector2& rhs); //setY method of Vector2 based on Vector2
        float getX() const; //the x getter
        float getY() const; //the y getter
    private:
        float x; //x on a plane represented as a vector2
        float y; //y on a plane represented as a vector2
    };
}
