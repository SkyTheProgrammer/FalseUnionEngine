#pragma once
#include "FalseUnion.h"

class Sandbox2D : public FalseUnion::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;
    
    void OnAttach() override;
    void OnDetach() override;
    
    void OnUpdate(FalseUnion::Timestep timestep) override;
    void OnImGuiRender() override;
    void OnEvent(FalseUnion::Event& event) override;
private:
    FalseUnion::OrthographicCameraController m_CameraController;

    FalseUnion::Ref<FalseUnion::VertexArray> m_SquareVertexArray;
    FalseUnion::Ref<FalseUnion::Shader> m_FlatColourShader;
    FalseUnion::Ref<FalseUnion::Texture2D> m_Texture;

    glm::vec4 m_SquareColour = glm::vec4(0.2f, 0.3f, 0.8f, 1.0f);
    
};
