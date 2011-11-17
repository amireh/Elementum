#!/usr/bin/env bash

if [ $# -lt 3 ]; then
  echo "Usage: ./refactor.sh FILE WORD REPL"
  exit
fi

SRC=$1
ORIG=$2
REPL=$3
CWD=$PWD

if [ -f $f -a -r $f ]; then
  echo "sed-ing $SRC"
 sed "s/$ORIG/$REPL/g" "$SRC" > "$SRC.tmp" && mv "$SRC.tmp" "$SRC"
else
 echo "Error: Cannot read $SRC"
 exit
fi
