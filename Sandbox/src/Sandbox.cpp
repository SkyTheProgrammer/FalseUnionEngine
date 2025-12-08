#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.inl>

#include "FalseUnion.h"
#include "../../FalseUnion/vendor/imgui/imgui.h"



class TestLayer : public FalseUnion::Layer
{
public:
    TestLayer() : Layer("Test"), m_Camera(-1.6f, 1.6f, -1.0f, 1.0f), m_CameraPosition(0.0f)
    {
        
        m_VertexArray.reset(FalseUnion::VertexArray::Create());

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

        m_SquareVertexArray.reset(FalseUnion::VertexArray::Create());

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

        std::string textureShaderVertexSrc = R"(
        #version 330 core

        layout(location = 0) in vec3 a_Position;
        layout(location = 1) in vec2 a_TexCoord;

        uniform mat4 u_ViewProjection;
        uniform mat4 u_Transform;

        out vec2 v_TexCoord;
        
        void main()
        {
            v_TexCoord = a_TexCoord;
            gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
        }
        )";

        std::string TextureShaderFragmentSrc = R"(
        #version 330 core

        layout(location = 0) out vec4 colour;

        in vec2 v_TexCoord;

        uniform sampler2D u_Texture;

        void main()
        {
            colour = texture(u_Texture, v_TexCoord);
        }
        )";

        m_Shader.reset(FalseUnion::Shader::Create(vertexSrc, fragmentSrc));
        m_Shader2.reset(FalseUnion::Shader::Create(vertexSrc2, flatColourShaderSrc));
        m_TextureShader.reset(FalseUnion::Shader::Create(textureShaderVertexSrc, TextureShaderFragmentSrc));

        m_Texture = FalseUnion::Texture2D::Create("Assets/missingTexturePNG.png");
        std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_TextureShader)->Bind();
        std::dynamic_pointer_cast<FalseUnion::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
        m_ChernosLogo = FalseUnion::Texture2D::Create("Assets/literallyMe.png");
        
        
        
        
            
    }

    void OnUpdate(FalseUnion::Timestep timestep) override
    {
        if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_LEFT))
        {
            m_CameraPosition.x -= m_CameraMoveSpeed * timestep;
        }
        else if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_RIGHT))
        {
            m_CameraPosition.x += m_CameraMoveSpeed * timestep;
        }

        if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_UP))
        {
            m_CameraPosition.y += m_CameraMoveSpeed * timestep;
        }
        else if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_DOWN))
        {
            m_CameraPosition.y -= m_CameraMoveSpeed * timestep;
        }

        if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_A))
        {
            m_CameraRotation += m_CameraRotateSpeed * timestep;
        }
        else if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_D))
        {
            m_CameraRotation -= m_CameraRotateSpeed * timestep;
        }

        FalseUnion::RenderCommand::SetClearColour(glm::vec4(1.0f, 0.3f, 1.0f, 1.0f));
        FalseUnion::RenderCommand::Clear();

        m_Camera.SetPosition(m_CameraPosition);
        m_Camera.SetRotation(m_CameraRotation);

        FalseUnion::Renderer::BeginScene(m_Camera);
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

            
            m_Texture->Bind(0);
            FalseUnion::Renderer::Submit(m_SquareVertexArray, m_TextureShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
            m_ChernosLogo->Bind();
            FalseUnion::Renderer::Submit(m_SquareVertexArray, m_TextureShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
            
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
        FalseUnion::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<FalseUnion::KeyPressedEvent>(FU_BIND_EVENT_FN(TestLayer::OnKeyPressedEvent));
    }

    bool OnKeyPressedEvent(FalseUnion::KeyPressedEvent& event)
    {
        return false;
    }

private:
    FalseUnion::Ref<FalseUnion::Shader> m_Shader;
    FalseUnion::Ref<FalseUnion::Shader> m_Shader2, m_TextureShader;
    FalseUnion::Ref<FalseUnion::VertexArray> m_VertexArray;

    FalseUnion::Ref<FalseUnion::Texture2D> m_Texture;
    FalseUnion::Ref<FalseUnion::Texture2D> m_ChernosLogo;
    
    FalseUnion::Ref<FalseUnion::VertexArray> m_SquareVertexArray;

    FalseUnion::OrthographicCamera m_Camera;
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
        PushLayer(new TestLayer());
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
