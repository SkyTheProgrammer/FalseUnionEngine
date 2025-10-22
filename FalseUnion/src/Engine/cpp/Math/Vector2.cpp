//
// Created by SkyTFB on 10/7/2025.

#include "fupch.h"
#include "../../Headers/Math/Vector2.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for Vector2 setting x and y to 0
    /// </summary>
    Vector2::Vector2()
    {
        x = 0;
        y = 0;
    }

    /// <summary>
    /// Constructor for Vector2 that takes in x and y
    /// </summary>
    /// @param newX The parameter that becomes the x for Vector2
    /// @param newY The parameter that becomes the y for Vector2
    Vector2::Vector2(float newX, float newY)
    {
        x = newX;
        y = newY;
    }

    /// <summary>
    /// default destructor for Vector2.
    /// </summary>
    Vector2::~Vector2()
    = default;

    /// <summary>
    /// Modifies the + operator for Vector2, so that it can be used on Vector2.
    /// </summary>
    /// @param rhs takes in another Vector2 for use in math
    /// @return Vector2 representing the sum Vector2.
    Vector2 Vector2::operator+(const Vector2& rhs) const
    {
        return {this->x + rhs.x, this->y + rhs.y};
    }

    /// <summary>
    /// Modifies the - operator for Vector2, so that it can be used on Vector2.
    /// </summary>
    /// @param rhs takes in another Vector2 for use in math
    /// @return Vector2 representing the difference as Vector2
    Vector2 Vector2::operator-(const Vector2& rhs) const
    {
        return {this->x - rhs.x, this->y - rhs.y};
    }

    /// <summary>
    /// Modifies the * operator for Vector2, so that it can be used on Vector2.
    /// </summary>
    /// @param rhs takes in a float for use in math
    /// @return Vector2 Represents the product of Vector2 and the given float.
    Vector2 Vector2::operator*(float rhs) const
    {
        return {this->x * rhs, this->y * rhs};
    }

    /// <summary>
    /// Modifies the * operator for Vector2, so that it can be used on Vector2.
    /// </summary>
    /// @param rhs takes in a float for use in math
    /// @return Vector2 Represents the quotient of Vector2 and the given float.
    Vector2 Vector2::operator/(float rhs) const
    {
        return {this->x / rhs, this->y / rhs};
    }

    /// <summary>
    /// Returns the Length of Given Vector2
    /// </summary>
    /// @return float Representing the length of a given Vector2
    float Vector2::length() const
    {
        return std::sqrt(this->x * this->x + this->y * this->y);
    }

    /// <summary>
    /// Normalizes the Vector2 to a unit vector by dividing both components by length.
    /// </summary>
    /// @return Vector2 representing a unit vector achieved through normalization
    Vector2 Vector2::normalize() const
    {
        return {this->x / length(), this->y / length()};
    }

    /// <summary>
    /// Generates a Scalar for the Vector2's by multiplying their values together and adding
    /// </summary>
    /// @param rhs Vector2 to compare to.
    /// @return float Representing the scalar of the two Vector2's
    float Vector2::dot(const Vector2& rhs) const
    {
        return this->x * rhs.x + this->y * rhs.y;
    }

    /// <summary>
    /// Sets the Vector2's x and y to the given params x and y.
    /// </summary>
    /// @param newX the new x for the Vector2
    /// @param newY the new y for the Vector2
    void Vector2::setVector2(const float newX, const float newY)
    {
        x = newX;
        y = newY;
    }

    /// <sets the Vector2's x and y values to be the same as the params Vector2
    /// @param rhs Vector2 to be used to set x and y
    void Vector2::setVector2(const Vector2& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    /// <summary>
    /// Sets the x of Vector2 to the given float.
    /// </summary>
    /// @param newX Float to be used as new x of Vector2
    void Vector2::setX(const float newX)
    {
        this->x = newX;
    }

    /// <summary>
    /// Sets the y of Vector2 to the given float.
    /// </summary>
    /// @param newY Float to be used as new y of Vector2    
    void Vector2::setY(const float newY)
    {
        this->y = newY;
    }

    /// <summary>
    /// Sets the x of a Vector2 to match the given Vector2
    /// </summary>
    /// @param rhs Vector 2 to get the x from
    void Vector2::setX(const Vector2& rhs)
    {
        this->x = rhs.x;
    }

    /// <summary>
    /// Sets the Y of a Vector2 to match the given Vector2
    /// </summary>
    /// @param rhs Vector2 to get the y from.
    void Vector2::setY(const Vector2& rhs)
    {
        this->y = rhs.y;
    }

    /// <summary>
    /// Returns this Vector2's X
    /// </summary>
    /// @return Float representing this Vector2's X
    float Vector2::getX() const
    {
        return this->x;
    }

    /// <summary>
    /// Returns this Vector2's Y
    /// </summary>
    /// @return Float representing this Vector2's Y
    float Vector2::getY() const
    {
        return this->y;
    }
}
