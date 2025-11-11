#include "fupch.h"
#include "../../Headers/ImGui/ImGuiLayer.h"
#include "../../Headers/ImGui/ImGuiKeyTranslator.h"

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include "../../Headers/Core/Application.h"
#include "../../Headers/Core/KeyCodes.h"
#include "../../Headers/Core/Logger.h"
#include "glad/glad.h"

#define GUIKEYINDEX(x) FUTOGUI(x)-ImGuiKey_NamedKey_BEGIN

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
        
        ImGui_ImplOpenGL3_Init("#version 410");
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
        m_Time = time;
        
        // implement both new frame and render so that this has functionality next
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);
        

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    /// <summary>
    /// ImGuiLayers on event, attempts to handle the event passed, creates the event dispatcher.
    /// </summary>
    /// @param event Event&, event to try and be handled.
    void ImGuiLayer::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<MouseButtonPressedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<WindowResizeEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
        dispatcher.Dispatch<KeyTypedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
    }

    /// <summary>
    /// Handler for ImGuiLayers MouseButtonPressed Event.
    /// </summary>
    /// @param event MouseButtonPressedEvent&, reference to mouse button pressed event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[event.GetMouseCode()] = true;

        return false;
    }

    /// <summary>
    /// Handler for ImGuiLayers MouseButtonReleased Event.
    /// </summary>
    /// @param event MouseButtonReleasedEvent&, reference to mouse button released event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[event.GetMouseCode()] = false;

        return false;
    }

    /// <summary>
    /// Handler for ImGuiLayers MouseMoved Event.
    /// </summary>
    /// @param event MouseMovedEvent&, reference to mouse moved event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(event.GetMouseX(), event.GetMouseY());

        return false;
    }

    /// <summary>
    /// Handler for ImGuiLayers MouseScrolled Event.
    /// </summary>
    /// @param event MouseScrolledEvent&, reference to mouse scrolled event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheel += event.GetMouseY();
        io.MouseWheelH += event.GetMouseX();

        return false;
    }

    /// <summary>
    /// Handler for ImGuiLayers KeyPressed Event.
    /// </summary>
    /// @param event KeyPressedEvent&, reference to Key Pressed event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysData[GUIKEYINDEX(event.GetKeyCode())].Down = true;
        // io.KeysEvent doesnt seem to work and as such things like ctrl A dont work.

        io.KeyCtrl = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_CONTROL)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_CONTROL)].Down;
        io.KeyAlt = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_ALT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_ALT)].Down;
        io.KeyShift = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SHIFT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SHIFT)].Down;
        io.KeySuper = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SUPER)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SUPER)].Down;

        
        return false;
    }

    /// <summary>
    /// Handler for ImGuiLayers Key Released Event.
    /// </summary>
    /// @param event KeyReleasedEvent&, reference to Key released event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysData[GUIKEYINDEX(event.GetKeyCode())].Down = false;

        io.KeyCtrl = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_CONTROL)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_CONTROL)].Down;
        io.KeyAlt = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_ALT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_ALT)].Down;
        io.KeyShift = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SHIFT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SHIFT)].Down;
        io.KeySuper = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SUPER)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SUPER)].Down;

        
        return false;
    }

    /// <summary>
    /// Handler for ImGuiLayers Window Resize Event.
    /// </summary>
    /// @param event WindowResizeEvent&, reference to window resize event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, event.GetWidth(), event.GetHeight());
        
        return false;
    }

    /// <summary>
    /// Handler for ImGuiLayers Window Resize Event.
    /// </summary>
    /// @param event WindowResizeEvent&, reference to window resize event.
    /// @Returns bool, representing whether this handled the event.
    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        int eventKeyCode = event.GetKeyCode();
        if (eventKeyCode > 0 && eventKeyCode < 0x10000)
        {
            io.AddInputCharacter(static_cast<unsigned short>(eventKeyCode));
        }
        return false;
    }
}
