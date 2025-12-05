#include "fupch.h"
#include "../../Headers/graphics/RenderCommand.h"

#include "../../Headers/Platform/OpenGL/OpenGLRendererAPI.h"

namespace FalseUnion
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
