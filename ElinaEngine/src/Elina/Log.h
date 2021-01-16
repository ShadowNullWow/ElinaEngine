#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Elina
{
	class ELINA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define EL_CORE_TRACE(...)		::Elina::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EL_CORE_INFO(...)		::Elina::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EL_CORE_WARN(...)		::Elina::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EL_CORE_ERROR(...)		::Elina::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EL_CORE_FATAL(...)		::Elina::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define EL_TRACE(...)			::Elina::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EL_INFO(...)			::Elina::Log::GetClientLogger()->info(__VA_ARGS__)
#define EL_WARN(...)			::Elina::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EL_ERROR(...)			::Elina::Log::GetClientLogger()->error(__VA_ARGS__)
#define EL_FATAL(...)			::Elina::Log::GetClientLogger()->fatal(__VA_ARGS__)
