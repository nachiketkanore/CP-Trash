./gen > test_case
echo TESTCASE:
cat test_case

echo SOL OUTPUT:
./sol < test_case

echo BRUTE OUTPUT:
./brute < test_case
