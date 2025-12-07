#include "fupch.h"

#include "../../Headers/Graphics/VertexArray.h"
#include "../../Headers/Graphics/Renderer.h"

#include "../../Headers/Platform/OpenGL/OpenGLShader.h"


namespace FalseUnion
{
    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            FU_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::API::OpenGL:
            return new OpenGLShader(vertexSrc, fragmentSrc);
        default:
            FU_ENGINE_ASSERT(false, "Unknown RendererAPI!") return nullptr;
        }
    }
    
}
