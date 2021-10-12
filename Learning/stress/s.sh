for ((i=1;;i++)); do
	./gen > tc
	diff -w <(./sol < tc) <(python chk.py < tc) || break
	echo OK TEST $i
done
