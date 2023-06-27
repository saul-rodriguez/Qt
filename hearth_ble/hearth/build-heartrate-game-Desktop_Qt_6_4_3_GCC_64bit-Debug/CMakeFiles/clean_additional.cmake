# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/heartrate-game_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/heartrate-game_autogen.dir/ParseCache.txt"
  "heartrate-game_autogen"
  )
endif()
