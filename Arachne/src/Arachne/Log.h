#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Arachne {

	class ARACHNE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define ARA_CORE_ERROR(...)		::Arachne::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ARA_CORE_WARN(...)		::Arachne::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ARA_CORE_INFO(...)		::Arachne::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ARA_CORE_TRACE(...)		::Arachne::Log::GetCoreLogger()->trace(__VA_ARGS__)


// Client log marcos
#define ARA_ERROR(...)		::Arachne::Log::GetClientLogger()->error(__VA_ARGS__)
#define ARA_WARN(...)		::Arachne::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ARA_INFO(...)		::Arachne::Log::GetClientLogger()->info(__VA_ARGS__)
#define ARA_TRACE(...)		::Arachne::Log::GetClientLogger()->trace(__VA_ARGS__)
