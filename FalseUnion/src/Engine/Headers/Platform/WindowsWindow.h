#pragma once
#include "../Core/Window.h"
#include "GLFW/glfw3.h"

namespace FalseUnion
{
    class WindowsWindow : public Window // defines this class as a child of window
    {
    public:
        WindowsWindow(const WindowProperties& props); // defines its constructor that takes in WindowProperties
        virtual ~WindowsWindow(); // Virtual destructor

        void OnUpdate() override; // Declares override for OnUpdate method

        /// <summary>
        /// Getter for Width
        /// </summary>
        /// @returns unsigned int representing window width.
        unsigned int GetWidth() const override
        {
            return m_Data.Width;
        };

        /// <summary>
        /// Getter for height
        /// </summary>
        /// @returns unsigned int representing window height.
        unsigned int GetHeight() const override
        {
            return m_Data.Height;
        }; 

        /// <summary>
        /// Sets the EventCallback for this window
        /// </summary>
        /// @param callback EventCallbackFn&, a reference to the event callback function you want associated with this window.
        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
        
        void SetVSync(bool enabled) override; // Declares and overrides the SetVSync function.
        /// <summary>
        /// Returns wheather or not this window is set to VSync.
        /// </summary>
        /// @returns bool, True if class is currently Vsync false otherwise.
        bool IsVSync() const override
        {
            return m_Data.VSync;
        }; 

    private:
        virtual void Init(const WindowProperties& props); // virtual initializer with param for WindowPropteries reference
        virtual void Shutdown(); // declaration for  Virtual shutdown function
        GLFWwindow* m_Window; // pointer to window.

        struct WindowData // struct to help manage grouped window variables.
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data; // declaration of the above struct
    };
}
