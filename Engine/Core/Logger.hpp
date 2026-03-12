#pragma once

#include <string>
#include <format>

class Logger 
{
public:
    static void LogError(const std::string& message);
    static void LogWarning(const std::string& message);
    static void LogInfo(const std::string& message);
};

#define ENG_INFO(msg) Logger::LogInfo(std::format("[{}:{}] {}", __FILE__, __LINE__, msg))
#define ENG_ERROR(msg) Logger::LogError(std::format("[{}:{}] {}", __FILE__, __LINE__, msg))
#define ENG_WARNING(msg) Logger::LogWarning(std::format("[{}:{}] {}", __FILE__, __LINE__, msg))