#!/bin/bash

set -e

currDir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
mkdir -p ${currDir}/build

cd ${currDir}/build
<<<<<<< HEAD
cmake -G Ninja .. && ninja 
cd bin
./test_cpp
# GTEST_COLOR=1 ctest --verbose
=======
cmake -G Ninja .. && ninja 
>>>>>>> 39b3852d70e08a10293e88a1eeb97c1e73e8102e
