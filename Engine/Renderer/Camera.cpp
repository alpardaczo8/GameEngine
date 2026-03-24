#include <Renderer/Camera.hpp>

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspect, float nearPlane, float farPlane)
    : m_fov(fov), m_aspectRatio(aspect), m_nearPlane(nearPlane), m_farPlane(farPlane) 
{
    m_forward = glm::vec3(0.0f, 0.0f, -1.0f);
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getProjectionMatrix() const 
{
    return glm::perspective(glm::radians(m_fov), m_aspectRatio, m_nearPlane, m_farPlane);
}

glm::mat4 Camera::getViewMatrix() const 
{
    return glm::lookAt(m_position, m_position + m_forward, m_up);
}

void Camera::moveForward(float distance) 
{
    m_position += m_forward * distance;
}

void Camera::moveRight(float distance) 
{
    glm::vec3 right = glm::normalize(glm::cross(m_forward, m_up));
    m_position += right * distance;
}


