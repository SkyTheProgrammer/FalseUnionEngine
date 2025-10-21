workspace "FalseUnion" -- defines workspace
    architecture "x64" -- says we are only using 64 bit systems because i dont wanna build out for a depreciated architechture

    configurations {
    "Debug",
    "Release",
    "Dist"
} -- the configs I can build for

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- variable for the output dir with variable name based on differences in build.
    
project "FalseUnion" -- defines the FalseUnion part of the project
    location "FalseUnion" -- defines its location
    kind "SharedLib" -- says it a library
    language "C++" -- says its in c++

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- the directory that has the primary output files
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    } -- targets any header and c++ file in src folder
    
    filter "system:windows" -- filters for windows system
        cppdialect "c++20" -- makes sure you have the right c++ version
        staticruntime "On" -- makes runtime static
        systemversion "latest" -- defines lastest system version, don't know why latest isnt implicite but breaks otherwise.

        defines
            {
                "FU_PLATFORM_WINDOWS",
                "FU_BUILD_DLL" -- this macro is to point at its dll and help move it.
            }             -- Defines the two macros i set up in the code, one for the dll and one for making sure its windows.
-- These just define the different macros I set up for specific build types and specifics for how the program should act while in that type--
    filter "configurations:Debug"
        defines "FU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FU_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FU_DIST"
        optimize "On"

    filter {"system:windows", "configurations:Release"}
        buildoptions "/MT"

project "Sandbox" -- looks at the sandbox/client portion of my code
    location "Sandbox" -- defines location
    kind "ConsoleApp" -- says its an executable
    language "C++" -- defines its language

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- the directory that has the primary output files
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    } -- Targets all of its header and cpp files in src

    includedirs
    {
        "FalseUnion/src"
    } -- makes sure it includes FalseUnions src dir

    links
    {
        "FalseUnion"
    } -- defines a link to the false union end of the project
    
    
    filter "system:windows" -- same filter
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FU_PLATFORM_WINDOWS"
        } -- macro for windows

        postbuildcommands
                 {
                            
                    "{COPY} \"../bin/" .. outputdir .. "/FalseUnion/FalseUnion.dll\" \"%{cfg.targetdir}\""
                } -- defines a post build command to move false unions dll such that it shares a directory with this exe 
-- Same Filter build definitions as above --    
    filter "configurations:Debug"
        defines "FU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FU_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FU_DIST"
        optimize "On"

    filter {"system:windows", "configurations:Release"}
        buildoptions "/MT"