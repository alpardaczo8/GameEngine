#pragma once

#include <Platform/IWindow.hpp>
#include <Platform/SDL/SDLWindow.hpp>
#include <Renderer/Renderer.hpp>

#include <string>
#include <memory>

namespace Engine
{
    
class Application
{
private:
    std::unique_ptr<IWindow> m_window;
    Renderer m_renderer;
public:
    Application(/* args */);
    ~Application();

    void run();
};

}