#include "lua.h"

void doSomething(lua_State *L) {
  lua_newtable(L);
  lua_createtable(L, 1, 1);
}

