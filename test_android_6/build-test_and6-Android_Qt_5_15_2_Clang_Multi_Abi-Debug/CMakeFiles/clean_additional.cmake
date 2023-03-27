# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/test_and6_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/test_and6_autogen.dir/ParseCache.txt"
  "android-build"
  "test_and6_autogen"
  )
endif()
