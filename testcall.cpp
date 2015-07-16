#include <iostream>
#include <dlfcn.h>
using namespace std;

int main(int argc, char *argv[] ) {
  void *hdl = dlopen("libbar.dylib", RTLD_NOW);
  if(hdl == 0) {
    cout << dlerror() << endl;
    return -1;
  }
  cout << "hdl=" << (long)hdl << endl;
  void *f = dlsym(hdl, "lua_createtable");
  cout << "f=" << (long)f << endl;
  return 0;
}


