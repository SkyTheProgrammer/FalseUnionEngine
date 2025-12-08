#include "Sandbox2D.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.inl>

#include "../../FalseUnion/vendor/imgui/imgui.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
    
        m_SquareVertexArray = FalseUnion::VertexArray::Create();

        float squareVertices[3 * 4] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f, 0.5f, 0.0f, 
            -0.5f, 0.5f, 0.0f, 
        };

        FalseUnion::Ref<FalseUnion::VertexBuffer> SquareVertexBuffer(
            FalseUnion::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
        SquareVertexBuffer->SetLayout({
            {FalseUnion::ShaderDataType::Float3, "a_Position"}
        });
        m_SquareVertexArray->AddVertexBuffer(SquareVertexBuffer);


        uint32_t squareIndices[6] = {0, 1, 2, 2, 3, 0};
        FalseUnion::Ref<FalseUnion::IndexBuffer> SquareIndexBuffer(
            FalseUnion::IndexBuffer::Create(squareIndices, sizeof(squareIndices)));
        m_SquareVertexArray->SetIndexBuffer(SquareIndexBuffer);


        

        m_FlatColourShader = FalseUnion::Shader::Create("assets/shaders/FlatColour.glsl");
}

void Sandbox2D::OnDetach()
{
    
}

void Sandbox2D::OnUpdate(FalseUnion::Timestep timestep)
{
    m_CameraController.OnUpdate(timestep);
        
    FalseUnion::RenderCommand::SetClearColour(glm::vec4(1.0f, 0.3f, 1.0f, 1.0f));
    FalseUnion::RenderCommand::Clear();

        

    FalseUnion::Renderer::BeginScene(m_CameraController.GetCamera());
    {
            

        std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_FlatColourShader)->Bind();
        std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_FlatColourShader)->UploadUniformFloat4("u_Colour", m_SquareColour);
        
        FalseUnion::Renderer::Submit(m_SquareVertexArray, m_FlatColourShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
        
        FalseUnion::Renderer::EndScene();
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
