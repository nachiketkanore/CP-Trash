for ((i=1; ;i++)); do
	echo TEST $i
	./gen > tc
	diff -w <(./Fslow < tc) <(./F < tc) || break
done
