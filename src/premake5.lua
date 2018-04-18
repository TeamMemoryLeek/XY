t = dofile "templates.lua"

t.workspace("XY")

t.project("Core")
	kind "StaticLib"
	targetname "XYCore"
	files {
		"core/**.cpp",
		"core/**.h",
	}

group "Demos"

t.project("Framework")
	kind "ConsoleApp"
	targetname "XYFramework"
	debugdir "../res/"
	files {
		"demos/framework/**.cpp",
		"demos/framework/**.h",
	}
	links {
		"Core",
	}
