#pragma once

#include "../Core/Timestep.h"
#include "../Graphics/OrthographicCamera.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/MouseEvent.h"

namespace FalseUnion
{
    class OrthographicCameraController
    {
    public:
        OrthographicCameraController(float aspectRatio, bool rotation = false);


        void OnUpdate(Timestep timestep);
        void OnEvent(Event& e);

        OrthographicCamera& GetCamera()
        {
            return m_Camera;
        };

        const OrthographicCamera& GetCamera()
        const
        {
            return m_Camera;
        };

        void SetZoomLevel(float zoomLevel)
        {
            m_ZoomLevel = zoomLevel;
        }

        float GetZoomLevel() const
        {
            return m_ZoomLevel;
        }

    private:
        float m_AspectRatio = 1.0f;
        float m_ZoomLevel = 1.0f;
        OrthographicCamera m_Camera;
        bool m_Rotation = false;

        float m_CameraRotation = 0.0f;
        glm::vec3 m_CameraPosition = {0.0f, 0.0f, 0.0f};

        float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;

        bool OnMouseScrolled(MouseScrolledEvent& e);
        bool OnWindowResized(WindowResizeEvent& e);
    };
}
