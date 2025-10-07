//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_RENDERER_H
#define FALSEUNION_RENDERER_H
#include "Camera.h"
#include "Shader.h"
#include "Sprite.h"
#include "../Math/Vector2.h"

class Renderer {
    public:
    Renderer();
    void Initialize();
    void DrawSprite(Sprite sprite);
    void Flush();
    void SetCamera(Camera camera);
private:
    int VAO, VBO, EBO;
    Shader *shader;
    std::list<Vector2> vertices;
    std::list<int> indices;
    Camera *camera;
    void buffer();
    std::string LoadShader(std::string name);
};
#endif //FALSEUNION_RENDERER_H