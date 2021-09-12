for ((i = 1; i <= 1000; i++)); do
	./gen > tc
	# diff -w <(./ctt-slow < tc) <(./ctt < tc) || break
	time ./ctt < tc
	echo TEST $i OK
done
