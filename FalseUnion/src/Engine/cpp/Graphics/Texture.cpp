//
// Created by SkyTFB on 10/7/2025.
//

#include "fupch.h"

#include "../../Headers/Graphics/Texture.h"
#include "../../Headers/Graphics/Renderer.h"
#include "../../Headers/Platform/OpenGL/OpenGlTexture.h"

#include <memory>

namespace FalseUnion
{
    Ref<Texture2D> Texture2D::Create(const std::string path)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            FU_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLTexture2D>(path);
        default:
            FU_ENGINE_ASSERT(false, "Unknown RendererAPI!") return nullptr;
        }
    }

    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            FU_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLTexture2D>(width, height);
        default:
            FU_ENGINE_ASSERT(false, "Unknown RendererAPI!") return nullptr;
        }
    }
}
