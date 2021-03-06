#pragma once

#include <fmt/ostream.h>

#include <spdlog/spdlog.h>
#include <utils/macros.h>

BeginNamespaceOlympus

namespace logging
{
    enum class LogLevel : unsigned char
    {
        Debug = 0,
        Info,
        Warning,
        Error,
        Critical
    };

    void initialize();

    void setLogLevel(LogLevel logLevel);
    LogLevel getLogLevel();

    template <class ...TArgs>
    static void debug(const char* format, TArgs&&... args)
    {
        spdlog::debug(format, std::forward<TArgs>(args)...);
    }

    template <class ...TArgs>
    void info(const char* format, TArgs&&... args)
    {
        spdlog::info(format, std::forward<TArgs>(args)...);
    }

    template <class ...TArgs>
    void error(const char* format, TArgs&&... args)
    {
        spdlog::error(format, std::forward<TArgs>(args)...);
    }

    template <class ...TArgs>
    void critical(const char* format, TArgs&&... args)
    {
        spdlog::critical(format, std::forward<TArgs>(args)...);
    }

    template <class ...TArgs>
    void log(const char* format, TArgs&&... args)
    {
        spdlog::log(format, std::forward<TArgs>(args)...);
    }

    template <class ...TArgs>
    void warning(const char* format, TArgs&&... args)
    {
        spdlog::warn(format, std::forward<TArgs>(args)...);
    }
}

EndNamespaceOlympus
