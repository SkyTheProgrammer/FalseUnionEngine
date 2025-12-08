#include "Sandbox2D.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.inl>

#include "../../FalseUnion/vendor/imgui/imgui.h"

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
    m_CameraController.OnUpdate(timestep);
        
    FalseUnion::RenderCommand::SetClearColour(glm::vec4(1.0f, 0.3f, 1.0f, 1.0f));
    FalseUnion::RenderCommand::Clear();

        

    FalseUnion::Renderer2D::BeginScene(m_CameraController.GetCamera());
    {
        FalseUnion::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.4f, 1.0f});
        FalseUnion::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75f}, {0.4f, 0.2f, 0.8f, 1.0f});
        FalseUnion::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, {10.0f, 10.0f}, m_Texture);

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
