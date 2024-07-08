workspace "Arachne"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Includes relative to the root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Arachne/vendor/GLFW/include"



--include "Arachne/vendor/GLFW" <<<<<<<<<<<< this is to like the premake file in glfw, I do not know why this is nessicary as such I will wait untill I do, or just remove the premake file.

project "Arachne"
	location "Arachne"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "arapch.h"
	pchsource "Arachne/src/arapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}"
	}

	links
	{
		"Arachne/vendor/GLFW/bin/Debug-windows-x86_64/GLFW/GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ARA_PLATFORM_WINDOWS",
			"ARA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ARA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ARA_RELASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ARA_DIST"
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
			"Arachne/vendor/spdlog/include",
			"Arachne/src"
	}

	links
	{
		"Arachne"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{

			"ARA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ARA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ARA_RELASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ARA_DIST"
		optimize "On"

