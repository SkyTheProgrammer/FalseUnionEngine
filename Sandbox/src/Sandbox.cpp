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

        out vec3 v_Position;
        out vec4 v_Colour;

        void main()
        {
            v_Position = a_Position;
            v_Colour = a_Colour;
            gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

        out vec3 v_Position;
        out vec4 v_Colour;


        void main()
        {
            v_Position = a_Position;
            gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
        }
        )";

        std::string fragmentSrc2 = R"(
        #version 330 core

        layout(location = 0) out vec4 colour;

        in vec3 v_Position;

        void main()
        {
            colour = vec4(0.2, 0.5, 0.5, 1.0);
        }
        )";

        m_Shader.reset(new FalseUnion::Shader(vertexSrc, fragmentSrc));
        m_Shader2.reset(new FalseUnion::Shader(vertexSrc2, fragmentSrc2));
    }

    void OnUpdate() override
    {
        if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_LEFT))
        {
            m_CameraPosition.x -= m_CameraMoveSpeed;
        }
        else if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_RIGHT))
        {
            m_CameraPosition.x += m_CameraMoveSpeed;
        }

        if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_UP))
        {
            m_CameraPosition.y += m_CameraMoveSpeed;
        }else if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_DOWN))
        {
            m_CameraPosition.y -= m_CameraMoveSpeed;
        }

        if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_A))
        {
            m_CameraRotation += m_CameraRotateSpeed;
        } else if (FalseUnion::InputManager::IsKeyPressed(FU_KEY_D))
        {
            m_CameraRotation -= m_CameraRotateSpeed;
        }


        FalseUnion::RenderCommand::SetClearColour(glm::vec4(1.0f, 0.3f, 1.0f, 1.0f));
        FalseUnion::RenderCommand::Clear();

        m_Camera.SetPosition(m_CameraPosition);
        m_Camera.SetRotation(m_CameraRotation);

        FalseUnion::Renderer::BeginScene(m_Camera);
        {
            FalseUnion::Renderer::Submit(m_SquareVertexArray, m_Shader2);
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
    float m_CameraMoveSpeed = 0.1f;
    float m_CameraRotation = 0.0f;
    float m_CameraRotateSpeed = 1.0f;
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
