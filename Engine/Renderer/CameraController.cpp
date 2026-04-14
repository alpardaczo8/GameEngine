#include "Renderer/CameraController.hpp"

void CameraController::handleInput(const bool* keyboard, float deltaTime)
{
    float speed = 0.6f;
    if (keyboard[SDL_SCANCODE_W])
        m_camera.moveForward(speed * deltaTime);
    if (keyboard[SDL_SCANCODE_S])
        m_camera.moveForward(-speed * deltaTime);
    if (keyboard[SDL_SCANCODE_A])
        m_camera.moveRight(-speed * deltaTime);
    if (keyboard[SDL_SCANCODE_D])
        m_camera.moveRight(speed * deltaTime);
    if (keyboard[SDL_SCANCODE_E])
        m_camera.moveUp(speed * deltaTime);
    if (keyboard[SDL_SCANCODE_Q])
        m_camera.moveUp(-speed * deltaTime);
}

void CameraController::handleMouseMovement(float xOffset, float yOffset)
{
    const float sensitivity = 0.1f;
    m_camera.rotate(xOffset * sensitivity, -yOffset * sensitivity);
}