#!/usr/bin/env bash

ROOT="."
PKG="EClient"
if [ $# -gt 0 ]; then
  ROOT=$1
fi

OLDDIR=`pwd`
cd $ROOT

echo "@ Exporting ${PKG}.pkg to ${ROOT}/lua_${PKG}.cpp:"
tolua++ -n ${PKG} -o "${ROOT}/lua_${PKG}.cpp" "${ROOT}/${PKG}.pkg"
echo "@ Done!"

cd $OLDDIR
