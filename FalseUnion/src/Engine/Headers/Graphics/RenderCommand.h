#pragma once

#include "RendererAPI.h"
#include "VertexArray.h"
#include <memory>


namespace FalseUnion
{
    class RenderCommand
    {
    public:
        inline static void Init()
        {
            s_RendererAPI->Init();
        }
        static void SetClearColour(const glm::vec4& color)
        {
            s_RendererAPI->SetClearColor(color);
        }
        static void Clear()
        {
            s_RendererAPI->Clear();
        }
        static void DrawIndexed(const Ref<VertexArray>& vertexArray)
        {
            s_RendererAPI->DrawIndexed(vertexArray);
        }
    private:
        static RendererAPI* s_RendererAPI;
    };
}
