#pragma once

#include <Renderer/Camera.hpp>
#include <SDL3/SDL.h>

class CameraController
{
public:
    CameraController(Camera &camera) : m_camera(camera) {}
    void handleInput(const bool* keyboard, float deltaTime);
    void handleMouseMovement(float xOffset, float yOffset);

private:
    Camera &m_camera;
};
