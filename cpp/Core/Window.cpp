//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Window.h"

Window::Window(int width, int height, const std::string &title) {
        m_window = this;
        m_width = width;
        m_height = height;
        m_title = title;
}

int Window::getWidth() {
}

int Window::getHeight() {
}

int Window::getNativeWindow() {
}

void Window::FrameBuffer(Window window, int width, int height) {
}
