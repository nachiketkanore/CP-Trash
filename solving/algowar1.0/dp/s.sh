#!/bin/bash

# Rename file names accordingly
echo 'Compiling files'
g++ -O2 -std=c++17 -o sol sol.cpp
# g++ -O2 -std=c++17 -o brute brute.cpp
g++ -O2 -std=c++17 -o gen gen.cpp
echo 'Compilation done'

for((i = 1; i <= 60; ++i))
do
  echo $i
  ./gen > randomtests/input$i.txt
  ./sol < randomtests/input$i.txt > randomtests/output$i.txt
done