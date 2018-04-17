templates = {}

function templates.workspace(name)
	workspace (name)

	location "../sln/"
	configurations {
		"Debug",
		"Release",
	}
	platforms {
		"x86",
		"x64",
	}
end

function templates.project(name)
	project (name)

	location "../sln/%{wks.name}/"
	objdir "../obj/"
	targetdir "../bin/"

	flags {
		"MultiProcessorCompile",
	}

	filter {"configurations:Debug"}
		defines {
			"DEBUG",
		}

	filter {"configurations:Release"}
		defines {
			"RELEASE",
			"NDEBUG",
		}

	filter {}
end

return templates
