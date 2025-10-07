//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Graphics/Camera.h"

Camera::Camera(float x, float y, float width, float height) : m_viewSize(2560, 1600), m_projectionSize(width, height),
                                                              m_position(x, y), m_rotation(0), m_zoom(0) {
}

void Camera::SetPosition(float x, float y) {
}

void Camera::SetRotation(float angle) {
}

void Camera::SetZoom(float zoom) {
}

Vector2 Camera::GetPosition() {
}

float Camera::GetRotation() {
}

Vector2 Camera::GetViewSize() {
}

Vector2 Camera::GetProjection() {
}
