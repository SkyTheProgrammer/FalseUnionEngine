//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include <string>

#include "../Core/Core.h"

namespace FalseUnion
{
    class Texture
    {
    public:
        virtual ~Texture() = default; // Virtual deconstructor for texture.
        
        virtual uint32_t GetWidth() const = 0; // Get Width Method for texture
        virtual uint32_t GetHeight() const = 0; // Get Height Method for texture

        virtual void Bind(uint32_t slot = 0) const = 0; // Bind method for texture
        
        
    };

    class Texture2D : public Texture
    {
    public:
        static Ref<Texture2D> Create(const std::string path);
    };
    
}
