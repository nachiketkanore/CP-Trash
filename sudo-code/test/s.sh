for ((i = 1; i <= 1000; i++)); do
	./gen > tc
	diff -w <(./D < tc) <(python sol.py < tc) || break
	echo TEST $i OK
done
