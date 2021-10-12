for ((i=1; ; i++)) do
	echo TEST: $i
	./gen > int
	diff -w <(./seg < int) <(./seg_ < int) || break
done

