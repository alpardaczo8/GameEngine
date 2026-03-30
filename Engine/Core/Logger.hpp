#pragma once

#include <string>
#include <format>

constexpr const char* extractFilename(const char* path) {
    const char* file = path;
    while (*path) {
        if (*path == '/' || *path == '\\')
            file = path + 1;
        ++path;
    }
    return file;
}

class Logger 
{
public:
    static void LogError(const std::string& message);
    static void LogWarning(const std::string& message);
    static void LogInfo(const std::string& message);
};

#define ENG_INFO(msg) Logger::LogInfo(std::format("[{}:{}] {}", extractFilename(__FILE__), __LINE__, msg))
#define ENG_ERROR(msg) Logger::LogError(std::format("[{}:{}] {}", extractFilename(__FILE__), __LINE__, msg))
#define ENG_WARNING(msg) Logger::LogWarning(std::format("[{}:{}] {}", extractFilename(__FILE__), __LINE__, msg))