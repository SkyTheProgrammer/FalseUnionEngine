//
// Created by SkyTFB on 10/6/2025.
//

#pragma once

#include "../Math/Vector2.h"

namespace FalseUnion
{
    class Camera
    {
    public:
        Camera(); // default camera constructor
        virtual ~Camera(); // virtual camera destructor in case of inheratence
        Camera(float x, float y, float width, float height); // camera constructor with params for position and size.
        void SetPosition(float x, float y); // sets camera positon to given params
        void SetRotation(float angle); // sets camera rotation to given float
        void SetZoom(float zoom); // sets cameras zoom to given float
        Vector2<float> GetPosition(); // returns vector2 of cameras position
        float GetRotation(); // returns float of cameras rotation
        Vector2<float> GetViewSize(); // retuns vector2 of the current view dimensions
        Vector2<float> GetProjection(); // returns a vector 2 for its current projection dimentions

    private:
        Vector2<float> m_viewSize; // vector 2 representing width and height of cameras view
        Vector2<float> m_projectionSize; // vector2 representing width and height of cameras projection
        Vector2<float> m_position;  // vector 2 representing x and y of camera.
        float m_rotation; // float representing angle of camera relative to 0
        float m_zoom; // float representing how zoomed in or out the projection of camera is.
    };
}
