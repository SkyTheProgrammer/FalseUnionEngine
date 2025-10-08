//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_CAMERA_H
#define FALSEUNION_CAMERA_H
#include "../Math/Vector2.h"
//vector2 view size
//vector2 projectionsize
//vector2 position
class Camera {
public:
    Camera(float x, float y, float width, float height);
    void SetPosition(float x, float y);
    void SetRotation(float angle);
    void SetZoom(float zoom);
    Vector2 GetPosition();
    float GetRotation();
    Vector2 GetViewSize();
    Vector2 GetProjection();

    private:
        Vector2 m_viewSize;
        Vector2 m_projectionSize;
        Vector2 m_position;
        float m_rotation;
        float m_zoom;
};
#endif //FALSEUNION_CAMERA_H
