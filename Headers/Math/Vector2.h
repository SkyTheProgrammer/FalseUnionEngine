//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_VECTOR2_H
#define FALSEUNION_VECTOR2_H
class Vector2 {
    public:
        float x;
        float y;
        Vector2(float newX, float newY);
        Vector2 operator+(const Vector2& rhs) const;
        Vector2 operator-(const Vector2& rhs) const;
        Vector2 operator*(float rhs) const;
        Vector2 operator/(float rhs) const;
        [[nodiscard]] float length() const;
        [[nodiscard]] Vector2 normalize() const;
        [[nodiscard]] float dot(const Vector2& rhs) const;
        void setVector2(float newX, float newY);
};
#endif //FALSEUNION_VECTOR2_H