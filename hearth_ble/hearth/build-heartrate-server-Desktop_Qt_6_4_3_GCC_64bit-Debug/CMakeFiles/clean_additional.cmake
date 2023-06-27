# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/heartrate-server_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/heartrate-server_autogen.dir/ParseCache.txt"
  "heartrate-server_autogen"
  )
endif()
