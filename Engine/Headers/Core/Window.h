//
// Created by SkyTFB on 10/7/2025.
//

#ifndef FALSEUNION_WINDOW_H
#define FALSEUNION_WINDOW_H
#include <string>

class Window {
    public:
    Window(int width, int height, const std::string &title);
    int getWidth();
    int getHeight();
    int getNativeWindow();
private:
    Window *m_window;
    int m_width;
    int m_height;
    std::string m_title;
    void FrameBuffer(Window window, int width, int height);
};
#endif //FALSEUNION_WINDOW_H