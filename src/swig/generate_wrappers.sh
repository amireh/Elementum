#!/usr/bin/env bash

ROOT="."
if [ $# -gt 0 ]; then
  ROOT=$1
fi

OLDDIR=`pwd`
OUTDIR=../wrappers/

cd $ROOT/packages

function generate() {
  swig -c++ -lua -I$ROOT/../../../../Shared/src/swig/packages -o $OUTDIR/${2}_wrap.cxx $ARG ${1}.i
}

echo "@ Generating SWIG Lua wrappers"
generate Elementum Elementum
echo "@ Done!"

cd $OLDDIR
