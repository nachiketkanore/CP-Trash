for((i = 1; ;++i))
do
  ./gen > testcase
  ./brute < testcase > ans1
  ./sol < testcase > ans2

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
