#!/bin/bash

for i in in*
do
	j=$(echo $i | tail -c +3 | head -c 1)
	out="out$j.out"
	./sol < $i > "res$j.out"
	if [ -z "$(diff -B res$j.out $out)" ]
	then
		echo "Test $j: ok"
	else
		echo "Test $j: wa"
		echo "Correct answer:"
		cat $out
		echo "Author's answer:"
		cat "res$j.out"
	fi
done