#!/bin/bash

rm -rf output
mkdir output

cd output

cmake ..
make

./hello