cmake_minimum_required(VERSION 2.8)

# add_library(mylib mylib.cpp)
# add_executable(myexe myexecutable.cpp)
# target_link_libraries(myexe mylib)

set(luafiles lapi lcode ldebug ldump lgc lobject lopcodes lparser lstate lstring ltable lundump lmem ldo lfunc llex ltm lzio lvm)
message("luafiles ${luafiles}")

foreach(luafile ${luafiles})
    set( lua_src ${lua_src} lua/${luafile}.c)
endforeach()
message("lua_src ${lua_src}")

add_library(bar SHARED ${lua_src} useslua.c useslua.cpp)
add_executable(testcall testcall.cpp)
link_libraries(testcall bar)

