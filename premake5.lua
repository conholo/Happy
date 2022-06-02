workspace "Happy"
	architecture "x64"
	startproject "Happy"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirectories = {}
IncludeDirectories["GLFW"] =		"Happy/vendor/GLFW/include"
IncludeDirectories["glad"] =		"Happy/vendor/glad/include"
IncludeDirectories["glm"] =			"Happy/vendor/glm"
IncludeDirectories["entt"] =		"Happy/vendor/entt/include"
IncludeDirectories["ImGui"] =		"Happy/vendor/ImGui"
IncludeDirectories["stb_image"] =	"Happy/vendor/stb_image"
IncludeDirectories["yaml_cpp"] =	"Happy/vendor/yaml-cpp"

group "Dependencies"
	include "Happy/vendor/GLFW"
	include "Happy/vendor/glad"
	include "Happy/vendor/ImGui"
	include "Happy/vendor/yaml-cpp"
group ""

project "Happy"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	location "Happy"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/stb_image.h",
		"%{prj.name}/vendor/stb_image/stb_image.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/entt/include/entt.hpp",
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDirectories.GLFW}",
		"%{IncludeDirectories.glad}",
		"%{IncludeDirectories.glm}",
		"%{IncludeDirectories.entt}",
		"%{IncludeDirectories.ImGui}",
		"%{IncludeDirectories.stb_image}",
		"%{IncludeDirectories.yaml_cpp}/include",
	}

	links
	{
		"GLFW",
		"glad",
		"ImGui",
		"yaml-cpp"
	}

	pchheader "hpypch.h"
	pchsource "%{prj.name}/src/hpypch.cpp"

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "HPY_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HPY_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HPY_DIST"
		runtime "Release"
		optimize "on"


project "Application"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	location "Application"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"%{prj.name}/src",
		"Happy/src",
		"Happy/vendor",
		"Happy/vendor/spdlog/include",
		"%{IncludeDirectories.glm}",
		"%{IncludeDirectories.entt}",
		"%{IncludeDirectories.yaml_cpp}/include",
	}

	links 
	{
		"Happy"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "APP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "APP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "APP_DIST"
		runtime "Release"
		optimize "on"