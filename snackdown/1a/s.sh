for ((i = 1; i <= 1000; i++)); do
	echo TEST $i
	./gen > tc
	diff -w <(./minlcm1 < tc) <(./slow < tc) || break
done
