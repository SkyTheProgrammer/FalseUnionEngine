workspace "FalseUnion" -- defines workspace
    architecture "x64" -- says we are only using 64 bit systems because i dont wanna build out for a depreciated architechture

    configurations {
    "Debug",
    "Release",
    "Dist"
} -- the configs I can build for

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- variable for the output dir with variable name based on differences in build.
IncludeDir = {} -- Defines variable to hold includes
IncludeDir["GLFW"] = "FalseUnion/vendor/GLFW/include"           -- defines glfw's include in include variable.
IncludeDir["Glad"] = "FalseUnion/vendor/Glad/include"           -- defines glad's include in include variable.
IncludeDir["ImGui"] = "FalseUnion/vendor/imgui"                 -- defines imgui's include in the include variable.
IncludeDir["glm"] = "FalseUnion/vendor/glm"                     -- defines glm's include in the include variable.
IncludeDir["stb_image"] = "FalseUnion/vendor/stb_image"

include "FalseUnion/vendor/GLFW" -- includes GLFW's premake.
include "FalseUnion/vendor/Glad" -- includes Glad's premake.
include "FalseUnion/vendor/imgui" -- includes ImGui's premake.
    
project "FalseUnion" -- defines the FalseUnion part of the project
    location "FalseUnion" -- defines its location
    kind "StaticLib" -- says it a library
    language "C++" -- says its in c++
    cppdialect "c++20" -- makes sure you have the right c++ version
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- the directory that has the primary output files
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "fupch.h" -- defines the location of the precompiled header
    pchsource "FalseUnion/src/fupch.cpp" -- tells program we are using pch and this is its source

    dependson -- should be self explanitory
    { 
        "GLFW",
        "Glad",
        "ImGui"
    }
    

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/gml/glm/**.hpp",
        "%{prj.name}/vendor/gml/glm/**.inl",
    } -- targets any header and c++ file in src folder
    
    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }
    
    includedirs
    {
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
    } -- included directories for FalseUnion
    
    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib",
        "ImGui",
    } -- links to other librarys
    
    filter "system:windows" -- filters for windows system
        systemversion "latest" -- defines lastest system version, don't know why latest isnt implicite but breaks otherwise.

        defines
            {
                "FU_PLATFORM_WINDOWS",
                "FU_BUILD_DLL",
                "GLFW_INCLUDE_NONE"
            }             
-- These just define the different macros I set up for specific build types and specifics for how the program should act while in that type--
    filter "configurations:Debug" -- build type filter
        defines "FU_DEBUG" -- defines important things for build type, in this case the debug macro.
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "FU_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "FU_DIST"
        runtime "Release"
        optimize "On"

    filter {"system:windows", "configurations:Release"}
        runtime "Release"

project "Sandbox" -- looks at the sandbox/client portion of my code
    location "Sandbox" -- defines location
    kind "ConsoleApp" -- says its an executable
    language "C++"    -- defines its language
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- the directory that has the primary output files
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        
    } -- Targets all of its header and cpp files in src

    includedirs
    {
        "FalseUnion/src",
        "%{IncludeDir.glm}",
    } -- Includes dirs needed to run.

    links
    {
        "FalseUnion"
    } -- defines a link to the false union end of the project
    
    
    filter "system:windows" -- same filter
        cppdialect "c++20"
        
        systemversion "latest"

        defines
        {
            "FU_PLATFORM_WINDOWS"
        } -- macro for windows

-- Same Filter build definitions as above --    
    filter "configurations:Debug"
        defines "FU_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "FU_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "FU_DIST"
        runtime "Release"
        optimize "on"