#include "fupch.h"
#include "../../Headers/Graphics/RendererAPI.h"

namespace FalseUnion
{
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

    RendererAPI::~RendererAPI()
    = default;

    void RendererAPI::SetClearColor(const glm::vec4& color)
    {
    }

    void RendererAPI::Clear()
    {
    }

    void RendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
    {
    }
}
