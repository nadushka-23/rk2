#!/bin/bash
set -e

rm -rf build
mkdir build
cd build
cmake ..
cmake --build . --parallel $(nproc)
ctest --output-on-failure
cpack
