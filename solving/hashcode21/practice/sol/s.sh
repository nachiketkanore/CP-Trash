for file in a b c d e; do
	echo Working on input : $file
	./sol < $file.in > $file.out
done