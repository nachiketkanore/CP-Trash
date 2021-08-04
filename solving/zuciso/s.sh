for ((i = 1; ; i++)); do
	echo TEST $i 
	./gen > int
	diff -w <(./sol < int) <(./sol2 < int) || break
done