#!/usr/bin/env bash

ROOT="."
if [ $# -gt 0 ]; then
  ROOT=$1
fi

OLDDIR=`pwd`
OUTDIR=../wrappers/

cd $ROOT/packages

function generate() {
  swig -c++ -lua -I$ROOT/../../../../Shared/src/swig/packages -o $OUTDIR/${2}_wrap.cxx $3 ${1}.i
}

echo "@ Generating SWIG Lua wrappers"
generate Elementum Elementum
generate Ogre Ogre -nodefaultctor
generate OIS OIS -nodefaultctor
generate ParticleUniverse ParticleUniverse -nodefaultctor
swig -lua -external-runtime $OUTDIR/swigluarun.h
echo "@ Done!"

cd $OLDDIR
