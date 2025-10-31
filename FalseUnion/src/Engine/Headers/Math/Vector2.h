//
// Created by SkyTFB on 10/6/2025.
//
#pragma once



namespace FalseUnion

{
    template<typename vectorNumType> requires std::is_arithmetic_v<vectorNumType> class Vector2
    {
    public:
        /// <summary>
        /// constructor for Vector2. Defaults to 0.
        /// </summary>
        Vector2(vectorNumType newX = 0, vectorNumType newY = 0) : x(newX), y(newY) {} //Constructor with existing values

        /// <summary>
        /// Modifies the + operator for Vector2, so that it can be used on Vector2.
        /// </summary>
        /// @param rhs takes in another Vector2 for use in math
        /// @return Vector2 representing the sum Vector2.
        Vector2 operator+(const Vector2& rhs) const
        {
            return {this->x + rhs.x, this->y + rhs.y};
        } //modification to Vector2 + operator

        /// <summary>
        /// Modifies the - operator for Vector2, so that it can be used on Vector2.
        /// </summary>
        /// @param rhs takes in another Vector2 for use in math
        /// @return Vector2 representing the difference as Vector2
        Vector2 operator-(const Vector2& rhs) const
        {
            return {this->x - rhs.x, this->y - rhs.y};
        } //modification to Vector2 - operator

        /// <summary>
        /// Modifies the * operator for Vector2, so that it can be used on Vector2.
        /// </summary>
        /// @param rhs vectorNumType, takes in a number for use in math
        /// @return Vector2 Represents the product of Vector2 and the given number.
        Vector2 operator*(vectorNumType rhs) const
        {
            return {this->x * rhs, this->y * rhs};
        } //modification to Vector2 * operator

        /// <summary>
        /// Modifies the * operator for Vector2, so that it can be used on Vector2.
        /// </summary>
        /// @param rhs takes in a float for use in math
        /// @return Vector2 Represents the quotient of Vector2 and the given float.
        Vector2 operator/(vectorNumType rhs) const
        {
            return {this->x / rhs, this->y / rhs};
        } //modification to Vector2 / operator

        /// <summary>
        /// Returns the Length of Given Vector2
        /// </summary>
        /// @return float Representing the length of a given Vector2
        float length() const
        {
            return std::sqrt(this->x * this->x + this->y * this->y);
        } //Length method of Vector2

        /// <summary>
        /// Normalizes the Vector2 to a unit vector by dividing both components by length.
        /// </summary>
        /// @return Vector2 representing a unit vector achieved through normalization
        Vector2 normalize() const
        {
            return {this->x / length(), this->y / length()};
        } //Normalize method of Vector2

        /// <summary>
        /// Generates a Scalar for the Vector2's by multiplying their values together and adding
        /// </summary>
        /// @param rhs Vector2 to compare to.
        /// @return float Representing the scalar of the two Vector2's
        float dot(const Vector2& rhs) const
        {
            return this->x * rhs.x + this->y * rhs.y;
        } //dot method of Vector2

        /// <summary>
        /// Setter for Vector2. Uses two vars to assign x and y
        /// </summary>
        /// @param newX the new x for the Vector2
        /// @param newY the new y for the Vector2
        void setVector2(vectorNumType newX, vectorNumType newY)
        {
            x = newX;
            y = newY;
        } //the Set Function of Vector2 based on float

        /// <summary>
        /// Setter for vector 2 takes in a different vector 2. and copies its values.
        /// </summary>
        /// @param rhs Vector2 address to be copied over.
        void setVector2(const Vector2& rhs)
        {
            x = rhs.x;
            y = rhs.y;
        } //the Set Function of Vector2 based on Vector2

        /// <summary>
        /// Setter for the x of Vector2 to the given number.
        /// </summary>
        /// @param newX vectorNumbType, number to be used as new x of Vector2
        void setX(const vectorNumType newX)
        {
            x = newX;
        } //setX method of Vector2 based on float

        /// <summary>
        /// Setter for the y of Vector2 to the given number.
        /// </summary>
        /// @param newY vectorNumbType, number to be used as new y of Vector2
        void setY(const vectorNumType newY)
        {
            y = newY;
        } //setY method of Vector2 based on float

        /// <summary>
        /// Sets the x of a Vector2 to match the given Vector2
        /// </summary>
        /// @param rhs Vector 2 to get the x from
        void setX(const Vector2& rhs)
        {
            x = rhs.x;
        } //setX method of Vector2 based on Vector2

        /// <summary>
        /// Sets the Y of a Vector2 to match the given Vector2
        /// </summary>
        /// @param rhs Vector2 to get the y from.
        void setY(const Vector2& rhs)
        {
            y = rhs.y;
        } //setY method of Vector2 based on Vector2

        /// <summary>
        /// Returns this Vector2's X
        /// </summary>
        /// @return vectorNumType, number representing this Vector2's X
        vectorNumType getX() const
        {
            return x;
        } //the x getter

        /// <summary>
        /// Returns this Vector2's Y
        /// </summary>
        /// @return vectorNumType, number representing this Vector2's Y
        vectorNumType getY() const
        {
            return y;
        } //the y getter
        
    private:
         vectorNumType x; //x on a plane represented as a vector2
         vectorNumType y; //y on a plane represented as a vector2
    };
}
