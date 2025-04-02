#pragma once
#include <string>

namespace Logger
{
    enum class LogLevel
    {
        None,
        Error,
        Warning,
        Info,
    };

    extern LogLevel logLevel;

    std::string getTimeForLog();

    void log(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);
}
