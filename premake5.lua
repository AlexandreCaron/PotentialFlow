-- premake5.lua
workspace "PotentialFlow"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "PotentialFlow"

outputdir = "%{cfg.buildcfg}"

include "PotentialFlow"