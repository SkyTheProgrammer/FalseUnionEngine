//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include "Camera.h"
#include "Shader.h"
#include "Sprite.h"
#include "../Math/Vector2.h"

namespace FalseUnion{class Renderer {
    public:
    Renderer(); // default constructor for renderer
    virtual ~Renderer(); // virtual deconstructor in case of inheritance
    static void Initialize(); // initializes the renderer
    void DrawSprite(Sprite sprite); // draws the given sprite
    void Flush(); // flushes unused or un-needed objects.
    void SetCamera(Camera camera); // sets the camera to the given camera object.
private:
    //
    int VAO, VBO, EBO; // change this later for now store as int (Vertex Buffer Object VBO, Vertex Array Object VAO, and Element Buffer Object EBO)
    //
    Shader *shader; // assigns the shader
    std::list<Vector2> vertices; // list of vertices
    std::list<int> indices; // list of indices
    Camera *camera; // reference camera
    void buffer(); // buffer method
    std::string LoadShader(const std::string& name); // loader for the shader based on name.
    std::string LoadShader(int id); // loader for the shader based on name.
};}
