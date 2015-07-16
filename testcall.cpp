#include <iostream>
#include <dlfcn.h>
using namespace std;

void usesluacpp_testLua();

void testdlopen() {
  void *hdl = dlopen("libbar.dylib", RTLD_NOW);
  if(hdl == 0) {
    cout << dlerror() << endl;
    return -1;
  }
  cout << "hdl=" << (long)hdl << endl;
  void *f = dlsym(hdl, "lua_createtable");
  cout << "f=" << (long)f << endl;
}

int main(int argc, char *argv[] ) {
  // testdlopen();
  usesluacpp_testLua();
  return 0;
}


