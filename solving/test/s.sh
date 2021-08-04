for((i=0;;i++)); do
	echo $i
	./gen > in
	./sol < in || break
	# diff -w <(./sol < in) <(./brute < in) || break
done

for((i=0;i<=100;i++)); do
	echo $i
done
