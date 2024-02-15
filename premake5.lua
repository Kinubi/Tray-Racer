include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Tray Racer"
	architecture "x86_64"
	startproject "Tray Racer"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Tray Racer/vendor/GLFW"
	include "Tray Racer/vendor/Glad"
group ""

group "Core"
	include "Tray Racer"
group ""
