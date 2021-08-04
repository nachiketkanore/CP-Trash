for ((i=1;;i++)); do
	echo $i
	./gen > test
	./sol < test || break

done