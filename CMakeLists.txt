cmake_minimum_required(VERSION 4.0)
project(FalseUnion)

set(CMAKE_CXX_STANDARD 26)

add_executable(FalseUnion main.cpp
        Headers/Core/Logger.h
        Headers/Core/Timer.h
        Headers/Math/Vector2.h
        Headers/Graphics/Shader.h
        Headers/Graphics/Camera.h
        Headers/Graphics/Texture.h
        Headers/Graphics/Sprite.h
        Headers/Graphics/Colour.h
        Headers/Graphics/Renderer.h
        Headers/ECS/Attribute.h
        Headers/ECS/GameObject.h
        Headers/Input/Input.h
        Headers/Core/Window.h
        Headers/Core/Application.h
        cpp/Core/Timer.cpp
        cpp/Core/Logger.cpp
        cpp/Core/Application.cpp
        cpp/Core/Window.cpp
        cpp/ECS/Attribute.cpp
        cpp/ECS/GameObject.cpp
        cpp/Graphics/Camera.cpp
        cpp/Graphics/Colour.cpp
        cpp/Graphics/Renderer.cpp
        cpp/Graphics/Shader.cpp
        cpp/Graphics/Sprite.cpp
        cpp/Graphics/Texture.cpp
        cpp/Input/Input.cpp
        cpp/Math/Vector2.cpp
)
