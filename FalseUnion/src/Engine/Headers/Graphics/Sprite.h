//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include "Colour.h"
#include "Texture.h"
#include "../Math/Vector2.h"

namespace FalseUnion{class Sprite {
public:
    Sprite(); //Default constructor for sprite.
    Sprite(const Texture *texture, const Vector2& position, const Vector2& size, const float& rotation, const Colour* colour); //Constructor for sprite that intakes parameters to set important variables.
    virtual ~Sprite(); //virtual deconstructor in case of inheritance.
    void SetPosition(const Vector2& newPosition); //method to set sprite's position
    void SetSize(const Vector2& newSize); //method to set sprite's size
    void SetRotation(const float& newRotation); //method to set sprite's rotation
    void SetColour(const Colour *newColour); //method to set sprite's colour
    void SetTexture(const Texture *newTexture); // method to set sprite's texture
    Vector2 GetPosition(); // method to get sprite's position as vector 2
    Vector2 GetSize(); // method to get sprite's size as vector 2
    float GetRotation(); // method to get a float representing sprite's rotation
    Colour GetColor(); // method to get sprite's colour
private:
    Texture m_Texture; // declaration of sprite's texture
    Vector2 m_Position; // declaration of sprite's position
    Vector2 m_Size; // declaration of sprites's size
    float m_Rotation; // declaration of sprite's rotation
    Colour m_Colour; // declaration of sprites colour
};}
