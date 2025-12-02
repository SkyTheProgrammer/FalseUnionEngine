#include "fupch.h"
#include "../../Headers/Graphics/Buffer.h"

#include "../../Headers/Core/Core.h"
#include "../../Headers/Graphics/Renderer.h"
#include "../../Headers/Platform/OpenGL/OpenGlBuffer.h"

namespace FalseUnion
{
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            FU_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::OpenGL:
            return new OpenGLVertexBuffer(vertices, size);
        default:
            FU_ENGINE_ASSERT(false, "Unknown RendererAPI!") return nullptr;
        }
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            FU_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::OpenGL:
            return new OpenGLIndexBuffer(indices, size);
        default:
            FU_ENGINE_ASSERT(false, "Unknown RendererAPI!") return nullptr;
        }
    }
}
