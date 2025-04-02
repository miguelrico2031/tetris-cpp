#include "Logger.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

namespace Logger
{
    LogLevel logLevel = LogLevel::Info; // Definición de la variable global

    std::string getTimeForLog()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::tm buf;
        localtime_s(&buf, &in_time_t);
        std::ostringstream oss;
        oss << std::put_time(&buf, "%H:%M:%S");
        return oss.str();
    }

    void log(const std::string& message)
    {
        if (logLevel >= LogLevel::Info)
        {
            std::cout << getTimeForLog() << " Log: " << message << std::endl;
        }
    }

    void logWarning(const std::string& message)
    {
        if (logLevel >= LogLevel::Warning)
        {
            std::cout << getTimeForLog() << " Warning: " << message << std::endl;
        }
    }

    void logError(const std::string& message)
    {
        if (logLevel >= LogLevel::Error)
        {
            std::cout << getTimeForLog() << " Error: " << message << std::endl;
        }
    }
}
