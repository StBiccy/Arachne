#pragma once

#ifdef ARA_PLATFORM_WINDOWS
	#ifdef ARA_BUILD_DLL
		#define ARACHNE_API _declspec(dllexport)
	#else
		#define ARACHNE_API _declspec(dllimport)
	#endif // ARA_BULD_DLL
#else
	#error Arachne only supports Windows!
#endif // ARA_PLATFORM_WINDOWS

#ifdef ARA_ENABLE_ASSERTS
	#define ARA_ASSERT(x, ...) {if(!(x)) {ARA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ARA_CORE_ASSERT(x, ...) {if(!(x)) {ARA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define ARA_ASSERT(x, ...)
	#define ARA_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)