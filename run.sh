#!/bin/bash

mkdir build

machine=$(uname -a | cut -d \  -f 1)
if [[ $machine == Linux ]]; then {
  is_linux=1
} else {
  is_apple=1
} fi

compile_options=""
#if [[ -v is_linux ]]; then {
#  compile_options="${compile_options} -fPIC"
#} fi
#if [[ -v is_apple ]]; then {
  compile_options="${compile_options} "
#} fi

linker_options=""
#if [[ -v is_linux ]]; then {
#  linker_options="${linker_options} -shared"
#} fi
#if [[ -v is_apple ]]; then {
  linker_options="${linker_options} -dynamic"
#} fi
echo ${linker_options}

luafiles="lapi lcode ldebug ldump lgc lobject lopcodes lparser lstate lstring ltable lundump lmem ldo lfunc llex ltm lzio lvm"
objfiles=""
for file in ${luafiles}; do {
  echo $file
  cc -c ${compile_options} -o build/$file.o lua/$file.c
  objfiles="${objfiles} build/$file.o"
} done

echo $objfiles

c++ ${linker_options} -o build/liblua ${objfiles}

c++ -c -o build/testcall.o testcall.cpp
c++ -o build/testcall build/testcall.o -ldl
build/testcall

cc -c ${compile_options} -Ilua -o build/useslua.o useslua.c
c++ -c ${compile_options} -Ilua -o build/usesluacpp.o usesluacpp.cpp

c++ ${linker_options} -o build/liblua ${objfiles} build/useslua.o

c++ -c -o build/testcall.o testcall.cpp
c++ -o build/testcall build/testcall.o -ldl
build/testcall

c++ ${linker_options} -o build/liblua ${objfiles} build/useslua.o build/usesluacpp.o

c++ -c -o build/testcall.o testcall.cpp
c++ -o build/testcall build/testcall.o -ldl
build/testcall

