#!/usr/bin/env bash

if ! [[ -f "./build/" ]]; then
  mkdir ./build
fi

cd ./build
cmake .. || exit 1
make

