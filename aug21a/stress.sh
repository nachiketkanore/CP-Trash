#/bin/usr/bash
for((i=1; ;i++)); do
	echo TEST $i 
	./gen > int
	diff -w <(./arrfillSlow < int) <(./arrfill < int) || break
done
