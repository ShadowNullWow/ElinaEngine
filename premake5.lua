workspace "ElinaEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ElinaEngine"
	location "ElinaEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"EL_PLATFORM_WINDOWS",
			"EL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ElinaEngine/vendor/spdlog/include",
		"ElinaEngine/src"
	}

	links
	{
		"ElinaEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"EL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
		optimize "On"