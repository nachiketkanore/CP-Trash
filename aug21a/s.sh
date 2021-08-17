for((i=1; i<=2000; i++)); do
	echo TEST $i 
	./gen > int
	#cat int
	#./arrfillSlow < int
	diff -w <(./arrfillSlow < int) <(./arrfill < int) || break
done
