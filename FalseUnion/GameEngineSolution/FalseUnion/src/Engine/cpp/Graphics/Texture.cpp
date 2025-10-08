//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Graphics/Texture.h"

Texture::Texture() : width(0), height(0)
{
    filePath = "\\";
    textureID = 0;
}

Texture::Texture(std::string filepath, int id) : width(0), height(0)
{
    filePath = filepath;
    textureID = id;
}

void Texture::bind() {
}

void Texture::Unbind() {
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight() {
    return height;
}

int Texture::getID() {
    return textureID;
}
