//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Graphics/Texture.h"

namespace FalseUnion
{
    /// <summary>
    /// Defaults texture to 0 width and height, no filepath, and an id of 0
    /// </summary>
    Texture::Texture() : width(0), height(0)
    {
        filePath = "";
        textureID = 0;
    }

    /// <summary>
    /// Constructor that sets textures filepath and id based on params, defaults 0 for width and height.
    /// </summary>
    /// @param filepath String representing the filepath to the textures image.
    /// @param id int ID representing the way to find the Texture.
    Texture::Texture(const std::string& filepath, const int id) : width(0), height(0)
    {
        filePath = filepath;
        textureID = id;
    }

    /// <summary>
    /// Constructor that sets the textures filepath, id, and size based on params.
    /// </summary>
    /// @param filepath String representing the filepath to the textures image.
    /// @param id int ID representing the way to find the Texture.
    /// @param newWidth float representing the width of the texture
    /// @param newHeight float representing the height of the texture
    Texture::Texture(const std::string& filepath, const int id, const float newWidth, const float newHeight)
    {
        filePath = filepath;
        textureID = id;
        width = newWidth;
        height = newHeight;
    }

    /// <summary>
    /// Default Virtual Deconstructor for texture in case of inheritance.
    /// </summary>
    Texture::~Texture()
    = default;

    /// <summary>
    /// Class to be implemented that will bind a texture to a given object
    /// </summary>
    void Texture::bind()
    {
    }

    /// <summary>
    /// Class to be implemented that will Unbind a texture from a given object
    /// </summary>
    void Texture::Unbind()
    {
    }

    /// <summary>
    /// Returns a textures width as a float.
    /// </summary>
    /// @return float Textures width
    float Texture::getWidth()
    {
        return width;
    }

    /// <summary>
    /// Returns a textures height as a float.
    /// </summary>
    /// @return float Textures height
    float Texture::getHeight()
    {
        return height;
    }

    /// <summary>
    /// Returns a textures ID as an int
    /// </summary>
    /// @return int Textures ID
    int Texture::getID()
    {
        return textureID;
    }

    /// <summary>
    /// Takes in a float for width and height to set a textures size.
    /// </summary>
    /// @param newWidth float representing the new width of the texture
    /// @param newHeight float representing the new height of the texture
    void Texture::setSize(float newWidth, float newHeight)
    {
        this->width = newWidth;
        this->height = newHeight;
    }

    /// <summary>
    /// Takes in a float for width then sets the textures width to that.
    /// </summary>
    /// @param newWidth float representing the textures new width.
    void Texture::setWidth(float newWidth)
    {
        this->width = newWidth;
    }
    // if you're reading this hi :3
    /// <summary>
    /// Takes in a float for height and sets the textures height to that.
    /// </summary>
    /// @param newHeight float representing the textures new height.
    void Texture::setHeight(float newHeight)
    {
        this->height = newHeight;
    }
}
