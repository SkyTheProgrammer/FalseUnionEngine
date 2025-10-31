//
// Created by SkyTFB on 10/7/2025.
//

#include "fupch.h"
#include "../../Headers/Graphics/Camera.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for camera, sets all variables to 0.
    /// </summary>
    Camera::Camera()
    {
        m_viewSize = Vector2<float>(0,0);
        m_position = Vector2<float>(0,0);
        m_rotation = 0;
        m_zoom = 1;
        m_projectionSize = Vector2<float>(0,0);
    }

    /// <summary>
    /// default deconstructor for camera in case of inheratence.
    /// </summary>
    Camera::~Camera() = default;

    /// <summary>
    /// Camera with params to set position and size of camera.
    /// </summary>
    /// @param x float, representing the to be x coordinate of the camera   
    /// @param y float, representing the to be y coordinate of the camera
    /// @param width float, representing the to be width of the camera
    /// @param height float, representing the to be height of the camera
    Camera::Camera(float x, float y, float width, float height)
    {
        m_viewSize = Vector2(width,height);
        m_position = Vector2(x,y);
        m_rotation = 0;
        m_zoom = 1;
        m_projectionSize = Vector2<float>(0,0);
    }
    /// <summary>
    /// Sets the position of camera based off of parameters.
    /// </summary>
    /// @param x float representing the to be x coordinate of camera
    /// @param y float representing the to be y coordinate of camera
    void Camera::SetPosition(float x, float y)
    {
        m_position = Vector2(x,y);
    }

    /// <summary>
    /// Sets the rotation of camera based off of parameter.
    /// </summary>
    /// @param angle float, float representing the to be angle of the camera relative to 0
    void Camera::SetRotation(float angle)
    {
        m_rotation = angle;
    }

    /// <summary>
    /// Sets the zoom of camera based off of parameter.
    /// </summary>
    /// @param zoom float, float representing the to be zoom of the camera
    void Camera::SetZoom(float zoom)
    {
    }

    /// <summary>
    /// Returns the position of the camera as a Vector2
    /// </summary>
    /// @returns Vector2 position of camera
    Vector2<float> Camera::GetPosition()
    {
        return m_position;
    }

    /// <summary>
    /// Returns the rotation of the camera as a float
    /// </summary>
    /// @returns float rotation of camera
    float Camera::GetRotation()
    {
        return m_rotation;
    }

    /// <summary>
    /// Returns the size of the camera as a Vector2
    /// </summary>
    /// @returns Vector2 size of camera
    Vector2<float> Camera::GetViewSize()
    {
        return m_viewSize;
    }
    
    /// <summary>
    /// Returns the projection size of the camera as a Vector2
    /// </summary>
    /// @returns Vector2 projection size of camera
    Vector2<float> Camera::GetProjection()
    {
        return m_projectionSize;
    }
}
