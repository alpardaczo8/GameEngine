#include "Core/Logger.hpp"
#include <iostream>

void Logger::LogError(const std::string& message)
{
    std::cerr << "[ERROR] " << message << std::endl;
}

void Logger::LogWarning(const std::string& message)
{
    std::cerr << "[WARNING] " << message << std::endl;
}

void Logger::LogInfo(const std::string& message)
{
    std::cout << "[INFO] " << message << std::endl;
}