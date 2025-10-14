workspace "FalseUnion"
    architecture "x64"

    configurations {
    "Debug",
    "Release",
    "Dist"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
project "FalseUnion"
    location "FalseUnion"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    filter "system:windows"
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FU_PLATFORM_WINDOWS",
            "FU_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
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
        "FalseUnion/src"
    }

    links
    {
        "FalseUnion"
    }
    
    filter "system:windows"
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FU_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{COPY} %cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
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