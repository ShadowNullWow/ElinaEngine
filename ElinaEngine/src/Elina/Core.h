#pragma once

#ifdef EL_PLATFORM_WINDOWS
	#ifdef EL_BUILD_DLL
		#define ELINA_API __declspec(dllexport)
	#else
		#define ELINA_API __declspec(dllimport)
	#endif // EL_BUILD_DLL
#else
	#error Elina only support Windows!
#endif // EL_PLATFORM_WINDOWS
