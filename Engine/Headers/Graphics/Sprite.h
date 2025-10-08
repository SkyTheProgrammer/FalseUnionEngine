//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_SPRITE_H
#define FALSEUNION_SPRITE_H
#include "Colour.h"
#include "Texture.h"
#include "../Math/Vector2.h"

class Sprite {
public:
    void SetPostion(Vector2);
    void SetSize(Vector2);
    void SetRotation(float);
    void SetColor(Colour);
    void SetTexture(Texture);
    Vector2 GetPosition();
    Vector2 GetSize();
    float GetRotation();
    Colour GetColor();
private:
    Texture m_Texture;
    Vector2 m_Position;
    Vector2 m_Size;
    float m_Rotation;
    Colour m_Colour;
};
#endif //FALSEUNION_SPRITE_H