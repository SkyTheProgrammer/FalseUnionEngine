#pragma once


#include "Event.h"

namespace FalseUnion
{
    // Base Key Event class for others to inherit from, inherits from event.
    class KeyEvent : public Event
    {
    public:
        /// <summary>
        /// Returns the key code of this KeyEvent
        /// </summary>
        /// @returns int representing key code of this KeyEvent.
        int GetKeyCode() const { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(KeyboardEvt) // Defines the category as keyboard.

    protected:
        /// <summary>
        /// Protected constructor for KeyEvent, takes in int for KeyCode.
        /// </summary>
        /// @param keycode int to be assigned as this KeyEvents KeyCode
        KeyEvent(int keycode) : m_KeyCode(keycode)
        {
        }

        int m_KeyCode; // Key code declared as private
    };

    // key pressed event class inherits from key event
    class KeyPressedEvent : public KeyEvent
    {
    public:
        /// <summary>
        /// Constructor for KeyPressedEvent. Takes in key code as int and is held as bool. assigns both
        /// </summary>
        /// @param keycode int representing the code of the key pressed
        /// @param isHeld bool representing if the key has been held.
        KeyPressedEvent(int keycode, bool isHeld) : KeyEvent(keycode), m_IsHeld(isHeld)
        {
        }

        /// <summary>
        /// Getter for repeat count
        /// </summary>
        /// @returns int repeat count of key pressed.
        bool GetIsHeld() const { return m_IsHeld; }

        /// <summary>
        /// Override of ToString for KeyPressedEvent.
        /// </summary>
        /// @returns string, String that says "KeyPressedEvent:" then the keycode and its repeat count.
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << (m_IsHeld ? "Held" : "Initial press") << ")";
            return ss.str();
        }

        // macro definition with key pressed
        EVENT_CLASS_TYPE(KeyPressed)

    private:
        // bool for key held
        bool m_IsHeld;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        /// <summary>
        /// constructor for KeyReleasedEvent takes in and sets Keycode
        /// </summary>
        KeyReleasedEvent(int keycode) : KeyEvent(keycode)
        {
        }

        /// <summary>
        /// ToString override for keyreleased event print "KeyReleasedEvent: " then the key code.
        /// </summary>
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        // macro definition with key released
        EVENT_CLASS_TYPE(KeyReleased)
    };
}
