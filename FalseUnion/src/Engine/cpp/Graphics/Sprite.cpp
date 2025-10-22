//
// Created by SkyTFB on 10/7/2025.
//

#include "fupch.h"
#include "../../Headers/Graphics/Sprite.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for sprite
    /// </summary>
    Sprite::Sprite()
    = default;

    /// <summary>
    /// Default virtual deconstruction in case of inheritance
    /// </summary>
    Sprite::~Sprite()
    = default;

    /// <summary>
    /// Constructor for sprite that takes in necessary params to build a new sprite.
    /// </summary>
    /// @param texture Texture to be set as sprites reference texture
    /// @param position Vector2 Position for sprite to start at
    /// @param size Vector2 Size for sprite at start
    /// @param rotation float rotation of sprite at the start
    /// @param colour  initial colour of sprite
    Sprite::Sprite(const Texture* texture, const Vector2& position, const Vector2& size, const float& rotation,
                   const Colour* colour)
    {
        m_Texture = *texture;
        m_Position = position;
        m_Size = size;
        m_Rotation = rotation;
        m_Colour = *colour;
    }

    /// <summary>
    /// Sets the position of sprite to that of the parameter.
    /// </summary>
    /// @param newPosition Vector2 representing the new position of sprite
    void Sprite::SetPosition(const Vector2& newPosition)
    {
        m_Position = newPosition;
    }

    /// <summary>
    /// Sets the size of sprite to that of the parameter
    /// </summary>
    /// @param newSize vector2 representing the new size for the sprite
    void Sprite::SetSize(const Vector2& newSize)
    {
        m_Size = newSize;
    }

    /// <summary>
    /// Sets the rotation of sprite based off float param.
    /// </summary>
    /// @param newRotation float, sets this to the sprites rotation.
    void Sprite::SetRotation(const float& newRotation)
    {
        m_Rotation = newRotation;
    }

    /// <summary>
    /// Sets the colour of a sprite based off param.
    /// </summary>
    /// @param newColour Colour, sets this sprites colour to a reference of this colour
    void Sprite::SetColour(const Colour* newColour)
    {
        m_Colour = *newColour;
    }

    /// <summary>
    /// Sets the texture of a sprite based off param.
    /// </summary>
    /// @param newTexture Texture, sets this sprites texture to a reference of this colour
    void Sprite::SetTexture(const Texture* newTexture)
    {
        m_Texture = *newTexture;
    }

    /// <summary>
    /// Gets and returns the position of this sprite.
    /// </summary>
    /// @return Vector2 This sprites position
    Vector2 Sprite::GetPosition()
    {
        return m_Position;
    }

    /// <summary>
    /// Gets and returns the size of this sprite.
    /// </summary>
    /// @return Vector2 This sprites size
    Vector2 Sprite::GetSize()
    {
        return m_Size;
    }

    /// <summary>
    /// Gets and returns the roatation of this sprite.
    /// </summary>
    /// @return float This sprites rotation
    float Sprite::GetRotation()
    {
        return m_Rotation;
    }

    /// <summary>
    /// Gets and returns the colour of this sprite.
    /// </summary>
    /// @return Colour This sprites colour
    Colour Sprite::GetColor()
    {
        return m_Colour;
    }
}
