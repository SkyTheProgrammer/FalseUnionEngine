#pragma once

#include "../Layer/Layer.h"

#include "../Events/ApplicationEvent.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"

namespace FalseUnion{
    class FALSEUNION_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer(); // constructor for ImGui
        ~ImGuiLayer() override; // Destructor for ImGui


        virtual void OnAttach() override; // Declaration for ImGuiLayer's override of on attach method
        virtual void OnDetach() override; // Declaration for ImGuiLayer's override of on detach method
        virtual void OnImGuiRender() override;
        // virtual void OnUpdate() override; // Declaration for ImGuiLayer's override of on update method
        void Begin();
        void End();
        // void OnEvent(Event& event) override; // Declaration for ImGuiLayer's override of on event method
    private:
        // bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        // bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
        // bool OnMouseMovedEvent(MouseMovedEvent& event);
        // bool OnMouseScrolledEvent(MouseScrolledEvent& event);
        // bool OnKeyPressedEvent(KeyPressedEvent& event);
        // bool OnKeyReleasedEvent(KeyReleasedEvent& event);
        // bool OnKeyTypedEvent(KeyTypedEvent& event);
        // bool OnWindowResizeEvent(WindowResizeEvent& event);
        
        float m_Time = 0.0f;
    };
}
