#pragma once

#include "../Layer/Layer.h"

namespace FalseUnion{
    class FALSEUNION_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer(); // constructor for ImGui
        ~ImGuiLayer() override; // Destructor for ImGui


        void OnAttach() override; // Declaration for ImGuiLayer's override of on attach method
        void OnDetach() override; // Declaration for ImGuiLayer's override of on detach method
        void OnUpdate() override; // Declaration for ImGuiLayer's override of on update method
        void OnEvent(Event& event) override; // Declaration for ImGuiLayer's override of on event method
    private:
        float m_Time = 0.0f;
    };
}
