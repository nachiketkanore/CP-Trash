for ((i = 1; i <= 1000; i++)); do
	./gen > tc
	diff -w <(./digitrem < tc) <(./digitremSlow < tc) || break
	# echo "answers: "
	# ./digitrem < tc
	echo "case $i"
done
