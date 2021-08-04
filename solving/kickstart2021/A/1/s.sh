for ((i = 1; ;i++)); do
	./gen > int || break
	./sol < int || break
	echo OK $i
done