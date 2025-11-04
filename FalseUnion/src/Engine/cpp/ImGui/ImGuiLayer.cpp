#include "fupch.h"
#include "../../Headers/ImGui/ImGuiLayer.h"

#include "imgui.h"
#include "GLFW/glfw3.h"
#include "../../Headers/Core/Application.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for ImGuiLayer sets name to ImGuiLayer.
    /// </summary>
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
    {
    }

    /// <summary>
    /// Destructor for ImGuiLayer, for now left default may remain.
    /// </summary>
    ImGuiLayer::~ImGuiLayer()
    {
    }

    /// <summary>
    /// ImGuiLayer's on attach method, runs important methods when ImGui is attached. (context, Colour, init, etc)
    /// </summary>
    void ImGuiLayer::OnAttach()
    {
        //implement keycodes and an init so these work.
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors; // bitwise or operator holy I've never seen that before.
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
    }

    /// <summary>
    /// ImGuiLayer's on detach method, runs important code when this is detached.
    /// </summary>
    void ImGuiLayer::OnDetach()
    {
    }

    /// <summary>
    /// On update function for ImGuiLayer, ensures to set important ImGui things every update.
    /// </summary>
    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::GetApplication();
        io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow().GetWidth()), static_cast<float>(app.GetWindow().GetHeight()));

        float time = static_cast<float>(glfwGetTime());
        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
        
        // implement both new frame and render so that this has functionality next
        ImGui::NewFrame();

        
        

        ImGui::Render();
    }

    /// <summary>
    /// ImGuiLayers on event, attempts to handle the event passed.
    /// </summary>
    /// @param event Event&, event to try and be handled.
    void ImGuiLayer::OnEvent(Event& event)
    {
    }
}
