t = dofile "templates.lua"

t.workspace("XY")

t.project("Core")
	kind "StaticLib"
	targetname "XYCore"
	files {
		"core/**.cpp",
		"core/**.h",
	}

t.project("Audio")
	kind "StaticLib"
	targetname "XYAudio"
	files {
		"audio/**.cpp",
		"audio/**.h",
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
		-- Project references
		"Audio",
		"Core",
		-- Static libraries
		"Xaudio2",
		"Dsound",
		"dxguid",
	}
