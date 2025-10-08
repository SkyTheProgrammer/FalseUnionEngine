//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Graphics/Sprite.h"

Sprite::Sprite(Texture* texture, Vector2 position, Vector2 size, float rotation, Colour colour) : m_Texture(Texture()),
    m_Position(Vector2()),
    m_Size(Vector2()), m_Colour(Colour())
{
}

void Sprite::SetPostion(Vector2) {
}

void Sprite::SetSize(Vector2) {
}

void Sprite::SetRotation(float) {
}

void Sprite::SetColor(Colour) {
}

void Sprite::SetTexture(Texture) {
}

Vector2 Sprite::GetPosition() {
    return m_Position;
}

Vector2 Sprite::GetSize() {
    return m_Size;
}

float Sprite::GetRotation() {
    return m_Rotation;
}

Colour Sprite::GetColor() {
    return m_Colour;
}
