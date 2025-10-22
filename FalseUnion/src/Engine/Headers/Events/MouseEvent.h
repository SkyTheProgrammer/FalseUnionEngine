#pragma once

#include "Event.h"

namespace FalseUnion
{
    class MouseButtonEvent : public Event
    {
    public:
        /// <summary>
        /// Getter for mouse code.
        /// </summary>
        int GetMouseCode() const { return m_MouseCode; }
        //macro for mouse button category
        EVENT_CLASS_CATEGORY(MouseButtonEvt)

    protected:
        /// <summary>
        /// Constructor for mouse Button Event, intakes and assigns mouse code.
        /// </summary>
        /// @param mouseCode int, represents to be mouse code.
        MouseButtonEvent(const int mouseCode) : m_MouseCode(mouseCode)
        {
        }

        int m_MouseCode; // variable to store mouse code.
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        /// <summary>
        /// constructor for MouseButtonPressedEvent, takes in and assigns MouseCode.
        /// </summary>
        /// @param mouseCode int, represents to be mouse code.
        MouseButtonPressedEvent(const int mouseCode) : MouseButtonEvent(mouseCode)
        {
        }

        /// <summary>
        /// Override for to string, returns "MouseButtonPressedEvent: " then the mouse code
        /// </summary>
        /// @returns string representing the event and mouse code.
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_MouseCode;
            return ss.str();
        }

        //macro defining mouse button pressed class type
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        /// <summary>
        /// constructor for MouseButtonReleasedEvent, takes in and assigns mouseCode.
        /// </summary>
        /// @param mouseCode int, representing to be mouse code.
        MouseButtonReleasedEvent(const int mouseCode) : MouseButtonEvent(mouseCode)
        {
        }

        /// <summary>
        /// Override for to string, returns "MouseButtonReleasedEvent: " then the mouse code
        /// </summary>
        /// @returns string representing the event and mouse code.
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_MouseCode;
            return ss.str();
        }
        // macro to assign mouse button released class type.
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

    class MouseEvent : public Event
    {
    public:
        /// <summary>
        /// Getter for mouse x, returns a float for mouse's x
        /// </summary>
        /// @returns float, mouse x
        float GetMouseX() const { return m_MouseX; }
        /// <summary>
        /// Getter for mouse Y, returns a float for mouse's Y
        /// </summary>
        /// @returns float, mouse Y
        float GetMouseY() const { return m_MouseY; }

        //macro to assign category mouse
        EVENT_CLASS_CATEGORY(MouseEvt)

    protected:
        /// <summary>
        /// Constructor for MouseEvt, intakes and assigns mouse x and y.
        /// </summary>
        /// @param x float, represents to be mouseX.
        /// @param y float, represents to be mouseY.
        MouseEvent(const float x, const float y) : m_MouseX(x), m_MouseY(y)
        {
        }

        float m_MouseX, m_MouseY; // variables to represent mouses x and y
    };

    class MouseMovedEvent : public MouseEvent
    {
    public:
        /// <summary>
        /// Constructor for mouse moved event Takes in 2 floats and assigns them x and y
        /// </summary>
        /// @param x int, to be assigned x
        /// @param y int, to be assigned y
        MouseMovedEvent(const float x, const float y) : MouseEvent(x,y)
        {
        }


        /// <summary>
        /// Override for to string, returns "MouseMoved: " then mouse X, mouse Y
        /// </summary>
        /// @returns string representing the event and mouse position.
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
        //macro defining mouse moved class type.
        EVENT_CLASS_TYPE(MouseMoved)
    };

    class MouseScrolledEvent : public MouseEvent
    {
    public:
        /// <summary>
        /// Constructor for mouse scrolled event, takes in 2 floats to represent the scroll amount and direction.
        /// </summary>
        /// @param x float, amount mouse scrolled left and right
        /// @param y float, amount mouse scrolled up and down.
        MouseScrolledEvent(const float x, const float y) : MouseEvent(x,y)
        {
        }

        /// <summary>
        /// Override for to string, returns "MouseScrolled: " then mouse X, mouse Y
        /// </summary>
        /// @returns string representing the event and mouse position.
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
        //macro defining this class type as mouse scrolled.
        EVENT_CLASS_TYPE(MouseScrolled)
    };
}
