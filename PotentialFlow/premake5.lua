project "PotentialFlow"
   kind "SharedLib"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "./include/**.h", "./sources/**.cpp" }

   includedirs
   {
      "./include",
      "I:/Libraries/Eigen"
   }

   links
   {
   }
   
   targetdir ("../Binaries")
   objdir ("../Intermediates")

   filter "system:windows"
      systemversion "latest"
      defines { "PLATFORM_WINDOWS",
                "EXPORTING"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      defines { "DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"
