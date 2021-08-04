for ((i = 1; ; i++)); do
	./gen > in || break
	diff -w <(./sol < in) <(./brute < in) || break
	echo TEST $i OK
done