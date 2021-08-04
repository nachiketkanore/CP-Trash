for file in a b c d e f; do
# for file in b c e f; do
	./sol < $file.in > $file.out || break
	echo DONE $file
done