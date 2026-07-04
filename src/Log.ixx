module;

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <string>

export module Log;

static std::shared_ptr<spdlog::logger> s_Logger;

export void LogInit()
{
    s_Logger = spdlog::stdout_color_mt("ENGINE");
    s_Logger->set_level(spdlog::level::trace);
    s_Logger->set_pattern("%^[%T] %n: %v%$");
}

export void LogInfo(const std::string& message) { s_Logger->info(message); }
export void LogWarn(const std::string& message) { s_Logger->warn(message); }
export void LogError(const std::string& message) { s_Logger->error(message); }