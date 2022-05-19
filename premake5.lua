workspace "Prune2D"
    architecture "x64"
    language "C++"
    cppdialect "C++latest"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Game"
    location "Game"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/intermediates/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs 
    {
        "vendor/glm",
        "vendor/imgui",
        "vendor/sol",
        "vendor/sdl/include",
        "vendor/lua",
        "vendor/spdlog/include",
        "vendor/entt/include"
    }
      
    libdirs
    {
        "vendor/sdl/lib/x64",
        "vendor/lua/lib",
    }
    
    links 
    {
        "SDL2.lib",
        "SDL2main.lib",
        "SDL2_image.lib",
        "SDL2_mixer.lib",
        "SDL2_ttf.lib",
    }
    
    linkoptions "liblua53.a"
                 
    filter "system.windows"
        cppdialect "C++latest"
        systemversion "latest"
        
    filter { "system:windows" }
        prebuildcommands { 
            "xcopy %{prj.location}\\..\\vendor\\lua\\lib\\lua53.dll %{prj.location}\\..\\bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\%{prj.name}\\lua53.dll /d",
            "xcopy %{prj.location}\\..\\vendor\\sdl\\lib\\x64\\*.dll %{prj.location}\\..\\bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\%{prj.name}\\*.dll /d",
        }