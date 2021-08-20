g++ -std=c++17 -fstack-protector-all -g -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -O2 -D DEBUG test.cpp -o test || echo "FAIL"

echo "compilation done.."
for ((i=1;i<=1000;i++)); do
	./gen > int
	./test < int > out || break
	echo TEST $i
done
