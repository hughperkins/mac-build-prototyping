extern "C" {
  #include "lua.h"
}

void doSomethingCpp(lua_State *L) {
  lua_createtable(L, 1, 1);
}

