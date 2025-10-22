//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include <string>

namespace FalseUnion
{
    class Texture
    {
    public:
        Texture(); // Default Constructor for texture
        Texture(const std::string& filepath, const int id); // Constructor for texture that intakes a file path and an id.
        Texture(const std::string& filepath, const int id, const float newWidth, const float newHeight); // Constructor for texture that intakes a filepath, id, as well as size.
        virtual ~Texture(); // Virtual deconstructor for texture.
        void bind(); // Bind method for texture
        void Unbind(); //Unbind method for texture
        float getWidth(); // Get Width Method for texture
        float getHeight(); // Get Height Method for texture
        int getID(); // Get ID method for texture
        void setSize(const float newWidth, float newHeight); // sets height and width
        void setWidth(float newWidth); // sets width
        void setHeight(float newHeight); // sets height
        
    private:
        int textureID; // Textures id
        float width, height; // Textures width and height.
        std::string filePath; // Textures File path
    };
}
