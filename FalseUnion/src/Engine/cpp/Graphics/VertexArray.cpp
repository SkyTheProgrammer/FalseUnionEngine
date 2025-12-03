#include "fupch.h"

#include "../../Headers/Graphics/VertexArray.h"
#include "../../Headers/Graphics/Renderer.h"
#include "../../Headers/Platform/OpenGL/OpenGLVertexArray.h"

namespace FalseUnion
{
    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            FU_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::OpenGL:
            return new OpenGLVertexArray();
        default:
            FU_ENGINE_ASSERT(false, "Unknown RendererAPI!") return nullptr;
        }
    }
    
}
