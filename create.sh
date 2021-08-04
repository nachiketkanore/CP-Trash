echo "nachiket kanore"
pwd
cp ~/.template/sol.cpp sol.cpp
# cp ~/.template/gen.cpp $1/gen.cpp
# cp ~/.template/s.sh $1/s.sh
# echo -e "/*\nAuthor: Nachiket Kanore\nCreated: $(date)\n*/\n$(cat $1/sol.cpp)" > $1/sol.cpp

# name=$(shuf -n 1 ~/.template/quotes)
# echo $name

echo -e "**/\n$(cat sol.cpp)" > sol.cpp
# echo -e "(ツ) $(shuf -n 1 ~/.template/quotes)\n$(cat sol.cpp)" > sol.cpp
echo -e " *\tCreated: $(date)\n$(cat sol.cpp)" > sol.cpp
# echo -e " *\tAuthor: Solve Machine\n$(cat sol.cpp)" > sol.cpp
echo -e " *\tAuthor: Nachiket Kanore\n$(cat sol.cpp)" > sol.cpp
echo -e "/**\n$(cat sol.cpp)" > sol.cpp
# subl $1/sol.cpp
echo 'Done'