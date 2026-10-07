#!/usr/bin/env bash

if ! [[ -f "./build/" ]]; then
  mkdir ./build
fi

cmake --build build || exit 1
cd .build/ && make

