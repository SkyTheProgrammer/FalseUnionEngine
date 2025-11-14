#include "fupch.h"
#include "../../../Headers/Platform/OpenGL/OpenGlContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../../../Headers/Core/Core.h"

FalseUnion::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
{
}

void FalseUnion::OpenGLContext::Init()
{
    glfwMakeContextCurrent(m_WindowHandle);

    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    FU_ENGINE_ASSERT(status, "Couldn't initalize glad.");
}

void FalseUnion::OpenGLContext::SwapBuffers()
{
    glfwSwapBuffers(m_WindowHandle);
}
