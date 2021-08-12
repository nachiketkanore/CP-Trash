for((i=1;;i++)); do
	./gen > tc
	diff -w <(./sol < tc) <(./brute < tc) || break
	echo OK $i
done
