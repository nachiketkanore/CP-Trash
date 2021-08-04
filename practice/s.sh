g++ -o sol D_ans.cpp
g++ -o brute d_brute.cpp
g++ -o gen gen.cpp

for ((i = 1; ; i++)); do

	echo $i
	./gen > test
	# cat test
	# ./sol < test > out
	# ./sol < test
	diff -w <(./sol < test) <(./brute < test) || break
done

# for ((i = 1; i <= 10; i++)); do
# 	subl solution$i.cpp
# done

# for ((i = 1; i <= 5; i++)); do
# 	touch que$i.cpp
# 	cp ~/CP/template.cpp que$i.cpp
# 	subl que$i.cpp
# done