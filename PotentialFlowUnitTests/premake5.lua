project "PotentialFlowUnitTests"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "./main.cpp", "./tests/**.cpp" }

   includedirs
   {
      "../PotentialFlow/include",
      "../Vendor/GoogleTest/include",
   }
   
   libdirs 
   {
    "../Vendor/GoogleTest/lib/x64"
   }

   links
   {
      "PotentialFlow",
      "gtest.lib",
      "gmock.lib"
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
   
      libdirs 
      {
       "../Vendor/GoogleTest/lib/x64/Debug"
      }

   filter "configurations:Release"
      defines { "RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"
   
      libdirs 
      {
       "../Vendor/GoogleTest/lib/x64/Release"
      }

   filter "configurations:Dist"
      defines { "DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"
   
      libdirs 
      {
       "../Vendor/GoogleTest/lib/x64/Release"
      }
