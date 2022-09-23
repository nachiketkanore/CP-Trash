g++ gen.cpp -o gen
for ((i = 1; ; i++)); do
	./gen > tc
	diff -w <(./sol < tc) <(./brute < tc) | exit 1
	echo TEST $i
done
