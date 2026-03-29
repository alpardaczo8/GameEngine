#include "Renderer/CameraController.hpp"

void CameraController::handleInput(const bool* keyboard, float deltaTime)
{
    if (keyboard[SDL_SCANCODE_W])
        m_camera.moveForward(0.01f * deltaTime * 60.0f); // Move forward at a speed of 0.01 units per second
    if (keyboard[SDL_SCANCODE_S])
        m_camera.moveForward(-0.01f * deltaTime * 60.0f); // Move forward at a speed of 0.01 units per second
    if (keyboard[SDL_SCANCODE_A])
        m_camera.moveRight(-0.01f * deltaTime * 60.0f); // Move right at a speed of 0.01 units per second
    if (keyboard[SDL_SCANCODE_D])
        m_camera.moveRight(0.01f * deltaTime * 60.0f); // Move right at a speed of 0.01 units per second
    if (keyboard[SDL_SCANCODE_E])
        m_camera.moveUp(0.01f * deltaTime * 60.0f);
    if (keyboard[SDL_SCANCODE_Q])
        m_camera.moveUp(-0.01f * deltaTime * 60.0f);
}

void CameraController::handleMouseMovement(float xOffset, float yOffset)
{
    const float sensitivity = 0.1f;
    m_camera.rotate(xOffset * sensitivity, -yOffset * sensitivity);
}