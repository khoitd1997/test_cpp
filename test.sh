#!/bin/bash
currDir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd ${currDir}/build
GTEST_COLOR=1 ctest --verbose