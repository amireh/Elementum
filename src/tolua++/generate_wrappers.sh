#!/usr/bin/env bash

ROOT="."
PKG="Elementum"
if [ $# -gt 0 ]; then
  ROOT=$1
fi

OLDDIR=`pwd`
cd $ROOT/packages

echo "@ Exporting packages/${PKG}.pkg to ${ROOT}/wrappers/${PKG}_wrap.cxx:"
tolua++ -n ${PKG} -o "${ROOT}/../wrappers/${PKG}_wrap.cxx" "${PKG}.pkg"
echo "@ Done!"

cd $OLDDIR
