#include <glm/ext/matrix_transform.hpp>

#include "FalseUnion.h"

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
        std::shared_ptr<FalseUnion::VertexBuffer> vertexBuffer;
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
        std::shared_ptr<FalseUnion::IndexBuffer> indexBuffer;
        indexBuffer.reset(FalseUnion::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVertexArray.reset(FalseUnion::VertexArray::Create());

        float squareVertices[3 * 4] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f, 0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f,
        };

        std::shared_ptr<FalseUnion::VertexBuffer> SquareVertexBuffer(
            FalseUnion::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
        SquareVertexBuffer->SetLayout({
            {FalseUnion::ShaderDataType::Float3, "a_Position"}
        });
        m_SquareVertexArray->AddVertexBuffer(SquareVertexBuffer);


        uint32_t squareIndices[6] = {0, 1, 2, 2, 3, 0};
        std::shared_ptr<FalseUnion::IndexBuffer> SquareIndexBuffer(
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

        uniform vec4 u_Colour;

        void main()
        {
            colour = u_Colour;
        }
        )";

        m_Shader.reset(new FalseUnion::Shader(vertexSrc, fragmentSrc));
        m_Shader2.reset(new FalseUnion::Shader(vertexSrc2, flatColourShaderSrc));
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

            glm::vec4 redColor = glm::vec4(0.8f, 0.2f, 0.3f, 1.0f);
            glm::vec4 blueColor = glm::vec4(0.2f, 0.3f, 0.8f, 1.0f);

            
            for (int y = 0; y < 20; y++)
            {
                for (int x = 0; x < 20; x++)
                {
                    glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
                    glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                    if (x % 2 ==0)
                    {
                        m_Shader2->UploadUniformFloat4("u_Colour", redColor);
                    }
                    else
                    {
                        m_Shader2->UploadUniformFloat4("u_Colour", blueColor);
                    }
                    FalseUnion::Renderer::Submit(m_SquareVertexArray, m_Shader2, transform);
                }
            }
            
            FalseUnion::Renderer::Submit(m_VertexArray, m_Shader);

            FalseUnion::Renderer::EndScene();
        }
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
    std::shared_ptr<FalseUnion::Shader> m_Shader;
    std::shared_ptr<FalseUnion::Shader> m_Shader2;
    std::shared_ptr<FalseUnion::VertexArray> m_VertexArray;

    std::shared_ptr<FalseUnion::VertexArray> m_SquareVertexArray;

    FalseUnion::OrthographicCamera m_Camera;
    glm::vec3 m_CameraPosition;
    float m_CameraMoveSpeed = 1.0f;
    float m_CameraRotation = 0.0f;
    float m_CameraRotateSpeed = 180.0f;
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
