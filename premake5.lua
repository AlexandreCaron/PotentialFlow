-- premake5.lua
workspace "PotentialFlow"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "PotentialFlowApp"

outputdir = "%{cfg.buildcfg}"

include "PotentialFlowApp"
include "PotentialFlow"
include "PotentialFlowUnitTests"