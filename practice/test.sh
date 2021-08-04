go() {
	mkdir $1 || return
	echo 'Done'
	cp ~/.template/sol.cpp $1/sol.cpp
	cp ~/.template/gen.cpp $1/gen.cpp
	cp ~/.template/s.sh $1/s.sh

	subl $1/sol.cpp
}

go PE128