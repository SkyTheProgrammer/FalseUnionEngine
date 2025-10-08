cmake_minimum_required(VERSION 4.0)
project(FalseUnion)

set(CMAKE_CXX_STANDARD 26)

add_executable(FalseUnion main.cpp
        Engine/Headers/Core/Logger.h
        Engine/Headers/Core/Timer.h
        Engine/Headers/Math/Vector2.h
        Engine/Headers/Graphics/Shader.h
        Engine/Headers/Graphics/Camera.h
        Engine/Headers/Graphics/Texture.h
        Engine/Headers/Graphics/Sprite.h
        Engine/Headers/Graphics/Colour.h
        Engine/Headers/Graphics/Renderer.h
        Engine/Headers/ECS/Attribute.h
        Engine/Headers/ECS/GameObject.h
        Engine/Headers/Input/InputManager.h
        Engine/Headers/Core/Window.h
        Engine/Headers/Core/Application.h
        Engine/cpp/Core/Timer.cpp
        Engine/cpp/Core/Logger.cpp
        Engine/cpp/Core/Application.cpp
        Engine/cpp/Core/Window.cpp
        Engine/cpp/ECS/GameObject.cpp
        Engine/cpp/Graphics/Camera.cpp
        Engine/cpp/Graphics/Colour.cpp
        Engine/cpp/Graphics/Renderer.cpp
        Engine/cpp/Graphics/Shader.cpp
        Engine/cpp/Graphics/Sprite.cpp
        Engine/cpp/Graphics/Texture.cpp
        Engine/cpp/Input/InputManager.cpp
        Engine/cpp/Math/Vector2.cpp
        Builder/header/Builder.h
        Builder/cpp/Builder.cpp
)
