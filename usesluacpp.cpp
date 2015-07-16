extern "C" {
  #include "lua.h"
}

void doSomethingCpp(lua_State *L) {
  lua_newtable(L);
  lua_createtable(L, 1, 1);
}

void usesluacpp_testLua() {
  lua_state *L = luaL_newstate();
  luaL_openlibs(L);
  lua_close(L);
}

