t = dofile "templates.lua"

t.workspace("XY")

t.project("Core")
	kind "StaticLib"
	targetname "XYCore"
	files {
		"code/**.cpp",
		"code/**.h",
	}
