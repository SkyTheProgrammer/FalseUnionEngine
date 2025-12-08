#pragma once

#include <glm/glm.hpp>
#include "VertexArray.h"
#include <memory>


namespace FalseUnion
{
    class RendererAPI
    {
    public:
        virtual ~RendererAPI();
        

        enum class API
        {
            None = 0,
            OpenGL = 1,
        };

        virtual void Init() = 0;
        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
        
        virtual void SetClearColor(const glm::vec4& color);
        virtual void Clear();

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray);
        static API GetAPI() { return s_API; }

    private:
        static API s_API;
    };
}
