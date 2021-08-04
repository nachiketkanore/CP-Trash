for ((i = 1; i <= 6; i++)); do
	echo TEST $i
	./sol < $i.in > $i.out || break
done