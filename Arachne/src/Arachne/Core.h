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

//shifts the bits for 1 over to the left by x ammount
// x = 1 
// 1 (00000001) << 1 -> BIT = (00000010) 
#define BIT(x) (1 << x)