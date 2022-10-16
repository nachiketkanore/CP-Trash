# for ((i = 1; ; i++));do
# 	echo $i
# 	./gen > tc
# 	diff -w <(./sol < tc) <(./test < tc) || break
# 	echo TEST $i OK
# done

for ((i = 1; ; i++));do
	./gen > tc
	./rohitrks < tc || break
	echo TEST $i OK
done
