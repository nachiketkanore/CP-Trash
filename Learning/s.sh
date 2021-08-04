for ((i=1; ; i++)) do
	echo TEST: $i
	./gen > int
	diff -w <(./F < int) <(./Fslow < int) || break
done

echo ~ALL TESTCASES PASSED!
