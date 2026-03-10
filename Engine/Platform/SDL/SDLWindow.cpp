#include "Platform/SDL/SDLWindow.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_init.h>

namespace Engine
{

SDLWindow::SDLWindow(int width, int height, const std::string& title)
{
    SDL_Init(SDL_INIT_VIDEO);
    createWindow(width, height, title);
    m_isOpen = true;
}

SDLWindow::~SDLWindow()
{
    destroyWindow();
}

void SDLWindow::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            // Handle quit event
            m_isOpen = false;
        }
    }
}

void SDLWindow::swapBuffers()
{
    SDL_GL_SwapWindow(m_window);
}

int SDLWindow::getWidth()
{
    int width;
    SDL_GetWindowSize(m_window, &width, nullptr);
    return width;
}

int SDLWindow::getHeight()
{
    int height;
    SDL_GetWindowSize(m_window, nullptr, &height);
    return height;
}

void SDLWindow::createWindow(int width, int height, const std::string& title)
{
    // m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL);
    // m_context = SDL_GL_CreateContext(m_window);
}

void SDLWindow::destroyWindow()
{
    // SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

}
