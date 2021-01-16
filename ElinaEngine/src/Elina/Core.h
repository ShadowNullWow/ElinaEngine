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

#ifdef EL_ENABLE_ASSERTS
	#define EL_ASSERT(x, ...) { if(!x) { EL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EL_CORE_ASSERT(x, ...) { if(!x) { EL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define EL_ASSERT(x, ...)
	#define EL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)