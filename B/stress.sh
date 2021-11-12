#!/bin/bash

echo 'Compiling files'
# g++ -O2 -std=c++17 -o sol sol.cpp
# g++ -O2 -std=c++17 -o brute brute.cpp
# g++ -O2 -std=c++17 -o gen gen.cpp
echo 'Compilation done'

for((i = 1; i <= 100; ++i))
do
  ./gen > testcase || break
  ./brute < testcase > ans1 || break
  ./sol < testcase > ans2 || break
  
  if diff -w ans1 ans2
  then
      echo $i OK
  else
      echo $i WA
      echo $'TESTCASE:'
      cat testcase
      echo $'\nCORRECT ANSWER:'
      cat ans1
      echo $'\nYOUR ANSWER:'
      cat ans2
      echo $'\n\n'
      exit
  fi
done
