#!/bin/bash

set -e

currDir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
mkdir -p ${currDir}/build

cd ${currDir}/build
cmake -G Ninja .. && ninja 