#pragma once

#include "Happy/Core/Memory.h"
#include "glm/gtx/string_cast.hpp"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace HPY
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		static void AddSink(const spdlog::sink_ptr& sinkPointer);

	private:
		static Ref<spdlog::logger> s_EngineLogger;
		static Ref<spdlog::logger> s_ClientLogger;

		static std::vector<spdlog::sink_ptr> s_Sinks;
	};
}


#define LOG_CORE_TRACE(...)		::HPY::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)		::HPY::Log::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)		::HPY::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)		::HPY::Log::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...)	::HPY::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define LOG_TRACE(...)			::HPY::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)			::HPY::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)			::HPY::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)			::HPY::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)		::HPY::Log::GetClientLogger()->critical(__VA_ARGS__)