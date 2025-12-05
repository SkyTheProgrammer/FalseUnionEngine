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

        virtual void SetClearColor(const glm::vec4& color);
        virtual void Clear();

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray);
        static API GetAPI() { return s_API; }

    private:
        static API s_API;
    };
}
