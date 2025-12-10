#include "Sandbox2D.h"

#include <chrono>
#include <iostream>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.inl>

#include "../../FalseUnion/vendor/imgui/imgui.h"
#include "../../FalseUnion/src/Engine/Headers/Core/Instrumentor.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
    m_Texture = FalseUnion::Texture2D::Create("Assets/Images/missingTexturePNG.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(FalseUnion::Timestep timestep)
{
    FU_PROFILE_FUNCTION();
    {
        FU_PROFILE_SCOPE("CameraController::OnUpdate");
        m_CameraController.OnUpdate(timestep);
    }
    FalseUnion::RenderCommand::SetClearColour(glm::vec4(1.0f, 0.3f, 1.0f, 1.0f));
    FalseUnion::RenderCommand::Clear();

    if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_J))
    {
        m_SquarePosition.x -= m_SquareSpeed * timestep;
    } else if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_L))
    {
        m_SquarePosition.x += m_SquareSpeed * timestep;
    }
    if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_K))
    {
        m_SquarePosition.y -= m_SquareSpeed * timestep;
    }
    if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_I))
    {
        m_SquarePosition.y += m_SquareSpeed * timestep;
    }
    
    FalseUnion::Renderer2D::BeginScene(m_CameraController.GetCamera());
    {
        FU_PROFILE_SCOPE("Renderer Prep");
        FalseUnion::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.4f, 1.0f});
        FalseUnion::Renderer2D::DrawQuad(m_SquarePosition, {0.5f, 0.75f}, m_SquareColour);
        FalseUnion::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, {10.0f, 10.0f}, m_Texture);
        FalseUnion::Renderer2D::DrawQuad({0.25f, -0.25f, 0.1}, {1.0f, 1.0f}, FalseUnion::Texture2D::Create("Assets/Images/literallyMe.png"));
        // std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_FlatColourShader)->Bind();
        // std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_FlatColourShader)->UploadUniformFloat4("u_Colour", m_SquareColour);
        //
        // FalseUnion::Renderer::Submit(m_SquareVertexArray, m_FlatColourShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

        FalseUnion::Renderer2D::EndScene();
    }
}

void Sandbox2D::OnImGuiRender()
{
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Colour", glm::value_ptr(m_SquareColour));

    ImGui::End();
}

void Sandbox2D::OnEvent(FalseUnion::Event& event)
{
    m_CameraController.OnEvent(event);
}
