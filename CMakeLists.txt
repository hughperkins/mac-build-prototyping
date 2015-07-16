cmake_minimum_required(VERSION 2.8)

# add_library(mylib mylib.cpp)
# add_executable(myexe myexecutable.cpp)
# target_link_libraries(myexe mylib)

set(luafiles lapi lcode ldebug ldump lgc lobject lopcodes lparser lstate lstring ltable lundump lmem ldo lfunc llex ltm lzio lvm lauxlib linit ltablib liolib lstrlib lmathlib ldblib lbaselib loslib loadlib)
message("luafiles ${luafiles}")

foreach(luafile ${luafiles})
    set( lua_src ${lua_src} lua/${luafile}.c)
endforeach()
message("lua_src ${lua_src}")

if(UNIX AND NOT APPLE)
  add_definitions(-DLUA_USE_LINUX)
endif()

include_directories(lua)
add_library(bar SHARED ${lua_src} useslua.c usesluacpp.cpp)
add_executable(testcall testcall.cpp)
target_link_libraries(testcall bar)

if(UNIX AND NOT APPLE)
  target_link_libraries(testcall dl)
endif()

