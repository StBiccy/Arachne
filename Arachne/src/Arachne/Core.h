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
