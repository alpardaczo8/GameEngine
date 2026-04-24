#include "Platform/SDL/SDLWindow.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <stdexcept>

namespace Engine
{

SDLWindow::SDLWindow(int width, int height, const std::string& title)
{
    
    createWindow(width, height, title);
    SDL_SetWindowRelativeMouseMode(m_window, true);
    m_isOpen = true;

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

SDLWindow::~SDLWindow()
{
    destroyWindow();
}

void SDLWindow::pollEvents()
{
    m_mouseDeltaX = 0.0f;  // reset before processing new events
    m_mouseDeltaY = 0.0f;
    m_scrollDeltaY = 0.0f;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        m_pressedKeys.clear();
        if (event.type == SDL_EVENT_QUIT)
        {
            // Handle quit event
            m_isOpen = false;
        }

        if (event.type == SDL_EVENT_KEY_DOWN && event.key.repeat == 0)
        {
            m_pressedKeys.insert(event.key.scancode);
            if (event.key.scancode == SDL_SCANCODE_ESCAPE)
                m_isOpen = false;
        }

        if (event.type == SDL_EVENT_MOUSE_MOTION)
        {
            m_mouseDeltaX += event.motion.xrel;
            m_mouseDeltaY += event.motion.yrel;
        }
        if (event.type == SDL_EVENT_MOUSE_WHEEL)
        {
            m_scrollDeltaY += event.wheel.y;
        }
    }
}

void SDLWindow::swapBuffers()
{
    SDL_GL_SwapWindow(m_window);
}

int SDLWindow::getWidth() const
{
    int width;
    SDL_GetWindowSize(m_window, &width, nullptr);
    return width;
}

int SDLWindow::getHeight() const
{
    int height;
    SDL_GetWindowSize(m_window, nullptr, &height);
    return height;
}

void SDLWindow::createWindow(int width, int height, const std::string& title)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Init(SDL_INIT_VIDEO);

    m_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL);
    m_context = SDL_GL_CreateContext(m_window);
}

void SDLWindow::destroyWindow()
{
    SDL_GL_DestroyContext(m_context);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

}
