#include "fupch.h"
#include "../../Headers/ImGui/ImGuiLayer.h"

#include <backends/imgui_impl_glfw.h>

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
        // //implement keycodes and an init so these work.
        // ImGui::CreateContext();
        // ImGui::StyleColorsDark();
        //
        // ImGuiIO& io = ImGui::GetIO();
        // io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors; // bitwise or operator holy I've never seen that before.
        // io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        //
        // ImGui_ImplOpenGL3_Init("#version 410");
        // Setup Dear ImGui context

        // ^legacy trying to move fully to their prebuilt renderer.

        if (ImGui::GetCurrentContext() != nullptr)
            return;
        
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
        //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

        
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui::StyleColorsDark();

        Application& app = Application::GetApplication();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::GetApplication();
        io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow().GetWidth()), static_cast<float>(app.GetWindow().GetHeight()));

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }


    /// <summary>
    /// ImGuiLayer's on detach method, runs important code when this is detached.
    /// </summary>
    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnImGuiRender()
    {
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
    }


    /// <summary>
    /// On update function for ImGuiLayer, ensures to set important ImGui things every update.
    /// </summary>
    // void ImGuiLayer::OnUpdate()
    // {
    //     // ImGuiIO& io = ImGui::GetIO();
    //     // Application& app = Application::GetApplication();
    //     // io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow().GetWidth()), static_cast<float>(app.GetWindow().GetHeight()));
    //     //
    //     // float time = static_cast<float>(glfwGetTime());
    //     // io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
    //     // m_Time = time;
    //     //
    //     // // implement both new frame and render so that this has functionality next
    //     // ImGui_ImplOpenGL3_NewFrame();
    //     // ImGui::NewFrame();
    //     //
    //     // static bool show = true;
    //     // ImGui::ShowDemoWindow(&show);
    //     //
    //     //
    //     // ImGui::Render();
    //     // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // }

    /// <summary>
    /// ImGuiLayers on event, attempts to handle the event passed, creates the event dispatcher.
    /// </summary>
    /// @param event Event&, event to try and be handled.
    // void ImGuiLayer::OnEvent(Event& event)
    // {
    //     EventDispatcher dispatcher(event);
    //     dispatcher.Dispatch<MouseButtonPressedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
    //     dispatcher.Dispatch<MouseButtonReleasedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
    //     dispatcher.Dispatch<MouseMovedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
    //     dispatcher.Dispatch<MouseScrolledEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
    //     dispatcher.Dispatch<KeyPressedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
    //     dispatcher.Dispatch<KeyReleasedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
    //     dispatcher.Dispatch<WindowResizeEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
    //     dispatcher.Dispatch<KeyTypedEvent>(FU_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers MouseButtonPressed Event.
    // /// </summary>
    // /// @param event MouseButtonPressedEvent&, reference to mouse button pressed event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     io.MouseDown[event.GetMouseCode()] = true;
    //
    //     return false;
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers MouseButtonReleased Event.
    // /// </summary>
    // /// @param event MouseButtonReleasedEvent&, reference to mouse button released event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     io.MouseDown[event.GetMouseCode()] = false;
    //
    //     return false;
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers MouseMoved Event.
    // /// </summary>
    // /// @param event MouseMovedEvent&, reference to mouse moved event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     io.MousePos = ImVec2(event.GetMouseX(), event.GetMouseY());
    //
    //     return false;
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers MouseScrolled Event.
    // /// </summary>
    // /// @param event MouseScrolledEvent&, reference to mouse scrolled event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     io.MouseWheel += event.GetMouseY();
    //     io.MouseWheelH += event.GetMouseX();
    //
    //     return false;
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers KeyPressed Event.
    // /// </summary>
    // /// @param event KeyPressedEvent&, reference to Key Pressed event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     io.KeysData[GUIKEYINDEX(event.GetKeyCode())].Down = true;
    //     // io.KeysEvent doesnt seem to work and as such things like ctrl A dont work.
    //
    //     io.KeyCtrl = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_CONTROL)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_CONTROL)].Down;
    //     io.KeyAlt = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_ALT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_ALT)].Down;
    //     io.KeyShift = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SHIFT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SHIFT)].Down;
    //     io.KeySuper = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SUPER)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SUPER)].Down;
    //
    //     
    //     return false;
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers Key Released Event.
    // /// </summary>
    // /// @param event KeyReleasedEvent&, reference to Key released event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     io.KeysData[GUIKEYINDEX(event.GetKeyCode())].Down = false;
    //
    //     io.KeyCtrl = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_CONTROL)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_CONTROL)].Down;
    //     io.KeyAlt = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_ALT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_ALT)].Down;
    //     io.KeyShift = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SHIFT)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SHIFT)].Down;
    //     io.KeySuper = io.KeysData[GUIKEYINDEX(FU_KEY_LEFT_SUPER)].Down || io.KeysData[GUIKEYINDEX(FU_KEY_RIGHT_SUPER)].Down;
    //
    //     
    //     return false;
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers Window Resize Event.
    // /// </summary>
    // /// @param event WindowResizeEvent&, reference to window resize event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
    //     io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
    //     glViewport(0, 0, event.GetWidth(), event.GetHeight());
    //     
    //     return false;
    // }
    //
    // /// <summary>
    // /// Handler for ImGuiLayers Window Resize Event.
    // /// </summary>
    // /// @param event WindowResizeEvent&, reference to window resize event.
    // /// @Returns bool, representing whether this handled the event.
    // bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& event)
    // {
    //     ImGuiIO& io = ImGui::GetIO();
    //     int eventKeyCode = event.GetKeyCode();
    //     if (eventKeyCode > 0 && eventKeyCode < 0x10000)
    //     {
    //         io.AddInputCharacter(static_cast<unsigned short>(eventKeyCode));
    //     }
    //     return false;
    // }
}
