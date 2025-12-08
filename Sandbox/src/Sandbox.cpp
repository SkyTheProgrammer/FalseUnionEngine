#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.inl>

#include "FalseUnion.h"
#include "../../FalseUnion/src/Entrypoint.h"
#include "Sandbox2D.h"
#include "../../FalseUnion/vendor/imgui/imgui.h"


class TestLayer : public FalseUnion::Layer
{
public:
    TestLayer() : Layer("Test"), m_CameraController(1280.0f / 720.0f, true), m_CameraPosition(0.0f)
    {
        
        m_VertexArray = FalseUnion::VertexArray::Create();

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        };
        FalseUnion::Ref<FalseUnion::VertexBuffer> vertexBuffer;
        vertexBuffer.reset(FalseUnion::VertexBuffer::Create(vertices, sizeof(vertices)));

        {
            FalseUnion::BufferLayout layout = {
                {FalseUnion::ShaderDataType::Float3, "a_Position"},
                {FalseUnion::ShaderDataType::Float4, "a_Colour"},
            };

            vertexBuffer->SetLayout(layout);
        }
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        unsigned int indices[3] = {0, 1, 2};
        FalseUnion::Ref<FalseUnion::IndexBuffer> indexBuffer;
        indexBuffer.reset(FalseUnion::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVertexArray = FalseUnion::VertexArray::Create();

        float squareVertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f
        };

        FalseUnion::Ref<FalseUnion::VertexBuffer> SquareVertexBuffer(
            FalseUnion::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
        SquareVertexBuffer->SetLayout({
            {FalseUnion::ShaderDataType::Float3, "a_Position"},
                {FalseUnion::ShaderDataType::Float2, "a_TextCoord"}
        });
        m_SquareVertexArray->AddVertexBuffer(SquareVertexBuffer);


        uint32_t squareIndices[6] = {0, 1, 2, 2, 3, 0};
        FalseUnion::Ref<FalseUnion::IndexBuffer> SquareIndexBuffer(
            FalseUnion::IndexBuffer::Create(squareIndices, sizeof(squareIndices)));
        m_SquareVertexArray->SetIndexBuffer(SquareIndexBuffer);

        std::string vertexSrc = R"(
        #version 330 core

        layout(location = 0) in vec3 a_Position;
        layout(location = 1) in vec4 a_Colour;

        uniform mat4 u_ViewProjection;
        uniform mat4 u_Transform;

        out vec3 v_Position;
        out vec4 v_Colour;

        void main()
        {
            v_Position = a_Position;
            v_Colour = a_Colour;
            gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
        }
        )";

        std::string fragmentSrc = R"(
        #version 330 core

        layout(location = 0) out vec4 colour;

        in vec3 v_Position;
        in vec4 v_Colour;

        void main()
        {
            colour = vec4(v_Position*0.5 + 0.5, 1.0);
            colour = v_Colour;
        }
        )";

        std::string vertexSrc2 = R"(
        #version 330 core

        layout(location = 0) in vec3 a_Position;

        uniform mat4 u_ViewProjection;
        uniform mat4 u_Transform;

        out vec3 v_Position;
        out vec4 v_Colour;


        void main()
        {
            v_Position = a_Position;
            gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
        }
        )";

        std::string flatColourShaderSrc = R"(
        #version 330 core

        layout(location = 0) out vec4 colour;

        in vec3 v_Position;

        uniform vec3 u_Colour;

        void main()
        {
            colour = vec4(u_Colour, 1.0);
        }
        )";

        

        m_Shader = FalseUnion::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);
        m_Shader2 = FalseUnion::Shader::Create("FlatColour", vertexSrc2, flatColourShaderSrc);
        auto textureShader = m_ShaderLibrary.Load("Assets/Shaders/Texture.glsl");

        m_Texture = FalseUnion::Texture2D::Create("Assets/Images/missingTexturePNG.png");
        std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(textureShader)->Bind();
        std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
        m_ChernosLogo = FalseUnion::Texture2D::Create("Assets/Images/literallyMe.png");
        
        
        
        
            
    }

    void OnUpdate(FalseUnion::Timestep timestep) override
    {
        m_CameraController.OnUpdate(timestep);
        
        FalseUnion::RenderCommand::SetClearColour(glm::vec4(1.0f, 0.3f, 1.0f, 1.0f));
        FalseUnion::RenderCommand::Clear();

        

        FalseUnion::Renderer::BeginScene(m_CameraController.GetCamera());
        {
            glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
            

            std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_Shader2)->Bind();
            std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_Shader2)->UploadUniformFloat3("u_Colour", m_SquareColour);
            
            for (int y = 0; y < 20; y++)
            {
                for (int x = 0; x < 20; x++)
                {
                    glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
                    glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                    FalseUnion::Renderer::Submit(m_SquareVertexArray, m_Shader2, transform);
                }
            }

            auto textureShader = m_ShaderLibrary.Get("Texture");
            
            m_Texture->Bind(0);
            FalseUnion::Renderer::Submit(m_SquareVertexArray, textureShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
            m_ChernosLogo->Bind();
            FalseUnion::Renderer::Submit(m_SquareVertexArray, textureShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
            
            FalseUnion::Renderer::EndScene();
        }
    }

    void OnImGuiRender() override
    {
        ImGui::Begin("Settings");
        ImGui::ColorEdit3("Square Colour", glm::value_ptr(m_SquareColour));
        ImGui::End();
    }

    void OnEvent(FalseUnion::Event& event) override
    {
        m_CameraController.OnEvent(event);
    }

    bool OnKeyPressedEvent(FalseUnion::KeyPressedEvent& event)
    {
        return false;
    }

private:
    FalseUnion::ShaderLibrary m_ShaderLibrary;
    FalseUnion::Ref<FalseUnion::Shader> m_Shader;
    FalseUnion::Ref<FalseUnion::Shader> m_Shader2;
    FalseUnion::Ref<FalseUnion::VertexArray> m_VertexArray;

    FalseUnion::Ref<FalseUnion::Texture2D> m_Texture;
    FalseUnion::Ref<FalseUnion::Texture2D> m_ChernosLogo;
    
    FalseUnion::Ref<FalseUnion::VertexArray> m_SquareVertexArray;

    FalseUnion::OrthographicCameraController m_CameraController;
    glm::vec3 m_CameraPosition;
    float m_CameraMoveSpeed = 1.0f;
    float m_CameraRotation = 0.0f;
    float m_CameraRotateSpeed = 180.0f;

    glm::vec3 m_SquareColour = {0.2f, 0.3f, 0.8f};
};

class Sandbox : public FalseUnion::Application //defines sandboxes extention of application
{
public:
    Sandbox()
    {
        //PushLayer(new TestLayer());
        PushLayer(new Sandbox2D());
    }

    ~Sandbox()
    {
    }
};

class Log : public FalseUnion::Logger // defines sandboxes extention of logger
{
public:
    Log()
    {
    }

    ~Log()
    {
    }
};


FalseUnion::Application* FalseUnion::CreateApplication()
// defines create application from the client such that the client can create it for the engine.
{
    return new Sandbox();
}

FalseUnion::Logger* FalseUnion::CreateLogger()
// defines create logger from the client such that the client can create it for the engine.
{
    return new Log();
}
