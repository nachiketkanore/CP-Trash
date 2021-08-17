#g++ -std=c++17 sol.cpp -o sol
#g++ -std=c++17 brute.cpp -o brute
#g++ -std=c++17 gen.cpp -o gen

for((i=1;;i++)); do
	./gen > int
	diff -w <(./brute < int) <(./sol < int) || break
	echo TEST $i OK
done
