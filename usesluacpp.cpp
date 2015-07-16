extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

#include <iostream>
using namespace std;

void doSomethingCpp(lua_State *L) {
  lua_newtable(L);
  lua_createtable(L, 1, 1);
}

void usesluacpp_testLua() {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  lua_close(L);
  cout << "usesluacpp_testLua()" << endl;
}

