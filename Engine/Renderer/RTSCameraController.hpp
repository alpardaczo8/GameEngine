#pragma once

#include <Renderer/Camera.hpp>

class RTSCameraController 
{
public:
    RTSCameraController(Camera &camera) : m_camera(camera) {}
    void handleInput(const bool* keyboard, float deltaTime);
    void handleMouseMovement(float xOffset, float yOffset);
    void handleMouseScroll(float yOffset);
    void panMove(float xOffset, float zOffset, float deltaTime);
private:
    Camera &m_camera;

    float m_panSpeed    = 5.0f;
    float m_zoomSpeed   = 10.0f;
    float m_zoomMin     = 1.0f;
    float m_zoomMax     = 10.0f;
    float m_pitchLocked = -45.0f;

    float m_rotationSensitivity = 0.1f;
    float m_scrollSensitivity = 0.5f;

    float m_boundXMin = -25.0f;
    float m_boundXMax = 25.0f;
    float m_boundZMin = -25.0f;
    float m_boundZMax = 25.0f;
};
