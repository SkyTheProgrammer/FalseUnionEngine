//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_TEXTURE_H
#define FALSEUNION_TEXTURE_H
#include <string>

class Texture {
public:
    Texture();
    Texture(std::string filepath, int id);
    void bind();
    void Unbind();
    int getWidth();
    int getHeight();
    int getID();
private:
    int textureID;
    int width, height;
    std::string filePath;
};

#endif //FALSEUNION_TEXTURE_H