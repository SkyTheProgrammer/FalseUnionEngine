#pragma once

#include "Event.h"

namespace FalseUnion
{
    class WindowResizeEvent : public Event
    {
        public:
        /// <summary>
        /// constructor for window resize event, intakes and assigns height and width.
        /// </summary>
        /// @param width unsigned int representing to be width
        /// @param height unsigned int representing to be height.
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

        /// <summary>
        /// getter for window resize event width
        /// </summary>
        /// @returns unsigned int width.
        unsigned int GetWidth() const { return m_Width; }
        /// <summary>
        /// getter for window resize event height
        /// </summary>
        /// @returns unsigned int height.
        unsigned int GetHeight() const { return m_Height; }

        /// <summary>
        /// ToString override, Returns string with "WindowResizeEvent: " then width, height
        /// </summary>
        /// @returns string, string representing the window resize event
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        //macro to assign class type WindowResize
        EVENT_CLASS_TYPE(WindowResize)
        //macro to assign class category application
        EVENT_CLASS_CATEGORY(ApplicationEvt)
        private:
        unsigned int m_Width, m_Height; // int for window height and width
    };

    // basic classes with not important information to pass.
    /// <summary>
    /// Event class for when a window is closed.
    /// </summary>
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(ApplicationEvt)
    };

    /// <summary>
    /// Event class for app tick.
    /// </summary>
    class AppTickEvent : public Event
    {
        public:
        AppTickEvent() = default;
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(ApplicationEvt)
    };
    /// <summary>
    /// Event class for app update.
    /// </summary>
    class AppUpdateEvent : public Event
    {
        public:
        AppUpdateEvent() = default;
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(ApplicationEvt)
    };

    /// <summary>
    /// event class for when app is rendered.
    /// </summary>
    class appRenderEvent : public Event
    {
        public:
        appRenderEvent() = default;
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(ApplicationEvt)
    };
}
