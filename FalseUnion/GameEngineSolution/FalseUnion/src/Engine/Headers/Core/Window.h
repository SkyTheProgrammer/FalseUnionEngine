//
// Created by SkyTFB on 10/7/2025.
//

#pragma once

#include <string>
#include "../Math/Vector2.h"

namespace FalseUnion
{
    class FALSEUNION_API Window
    {
    public:
        Window(); // default window constructor
        Window(int width, int height, const std::string& title); // window constructor with params for size and title.
        virtual ~Window(); // virtual destructor in case of inheritance.
        Vector2 getSize(); // getter for size
        int getNativeWindow(); // getter for native window
        std::string getTitle(); // getter for title
        void setTitle(const std::string& title); // setter for title
        void setSize(int width, int height); // setter for size
        void setPrimaryWindow();
    private:
        static Window* m_window; //the primary window.
        Vector2 m_size; // vector2 representing the size of window
        std::string m_title; // string representing the title of window
        void FrameBuffer(Window window, int width, int height); // a method to buffer frame
    };
}

