project "Tray Racer"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	--pchheader "hzpch.h"
	--pchsource "src/hzpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Glad}",
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib",
	}


	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

		links
		{
			"%{Library.WinSock}",
			"%{Library.WinMM}",
			"%{Library.WinVersion}",
			"%{Library.BCrypt}",
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

		links
		{
		}

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

		links
		{

		}

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"

		links
		{
		}