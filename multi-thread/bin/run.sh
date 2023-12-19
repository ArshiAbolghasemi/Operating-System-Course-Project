#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

cd "$1" || exit 1

make run