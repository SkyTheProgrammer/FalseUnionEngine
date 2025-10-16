#pragma once

#include <string>

#include "../Core/Core.h"

namespace FalseUnion
{
    enum class EventType
    {
        None = 0,
        KeyPressed, KeyHeld, KeyReleased,
        MouseButtonPressed, MouseButtonHeld, MouseButtonReleased, MouseMoved, MouseScrolled,
        AppTick, AppUpdate, AppRender,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved
    }; // enum class to define the types of event, Added everything I could think of needing might add or remove as I see necessity.

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
    virtual EventType GetEventType() const override { return GetStaticType();}\
    virtual const std::string GetName() const {return #type}
    
    enum EventCategory
    {
        None = 0,
        Input,
        Application,
        Keyboard,
        Mouse,
        MouseButton
    }; // enum for event category
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
    
    class FALSEUNION_API Event
    {
        // Outline a block event system.
        // Events must be dealt with as they enter
        // Try and move to a buffer system asap
    public:
        // define access to the event dispacher
        virtual EventType GetEventType() const = 0; // Virtual declartion for event type getter
        virtual const std::string GetName() const = 0; // virtual declaration for name getter
        virtual int GetCategoryFlag() const = 0; // virtual declaration for category getter
        virtual std::string ToString() const { return GetName(); }
        // virtual declarion for ToString, defines getname at top.

        /// <summary>
        /// method to check if event is in provided event category
        /// </summary>
        /// @param category EventCategory to check against the event.
        /// @returns Bool true if the event is in category false otherwise.
        bool IsInCategory(EventCategory category)
        {
            if (category == EventCategory::Input)
            {
                if (GetCategoryFlag() == EventCategory::Input || GetCategoryFlag() == EventCategory::Keyboard ||
                    GetCategoryFlag() == EventCategory::Mouse || GetCategoryFlag() == EventCategory::MouseButton)
                {
                    return true;
                }
            }
            return GetCategoryFlag() & category;
        }

    private:
        bool handled = false;
    };
}
