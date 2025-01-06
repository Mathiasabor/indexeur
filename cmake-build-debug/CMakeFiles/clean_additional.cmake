# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/indexeur_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/indexeur_autogen.dir/ParseCache.txt"
  "indexeur_autogen"
  )
endif()
