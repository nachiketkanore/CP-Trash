for ((i = 1; ; i++)); do
	echo TEST $i
	./gen > int || break
	time ./sol < int > out || break
	# time diff -w <(./sol < int) <(./brute < int) || break
done