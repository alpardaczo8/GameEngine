#pragma once
#include <Platform/IWindow.hpp>
#include <string>
#include <Platform/SDL/SDLWindow.hpp>
#include <memory>

namespace Engine
{
    
class Application
{
private:
    std::unique_ptr<IWindow> m_window;
public:
    Application(/* args */);
    ~Application();

    void run();
};

}