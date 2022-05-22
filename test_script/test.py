# format
# solution file: sol.cpp
# input files: in in1 in2 ..
# output files: out out1 out2 ..

import os

input_files = []
output_files = []

for file in os.listdir():
    if "in" in file:
        input_files.append(file)
    if "out" in file:
        output_files.append(file)

input_files.sort()
output_files.sort()

if len(input_files) == 0:
    os.system("echo No Input Files Detected")
    exit(0)

os.system(f"echo {input_files} {output_files}")

if len(input_files) != len(output_files):
    os.system("echo Input / Output files dont match")
    exit(0)


# compile sol.cpp
os.system("echo COMPILING sol.cpp")
os.system("g++ -D DEBUG -std=c++17 sol.cpp -o sol")


for test_case, (input, output) in enumerate(zip(input_files, output_files)):
    # ./sol < input
    os.system(f"./sol < {input} > my_sol")
    if os.system(f"diff -w my_sol {output} > /dev/null"):
        os.system("echo ====================TESTCASE FAILED====================\n")
        os.system("echo")
        os.system(f"echo FILE NAMES: {input} {output}")
        os.system("echo TESTCASE: ")
        os.system(f"cat {input}")
        os.system("echo CORRECT OUTPUT: ")
        os.system(f"cat {output}")
        os.system("echo YOUR OUTPUT: ")
        os.system("cat my_sol")
        os.system("echo")
        os.system("echo ====================TESTCASE FAILED====================\n")
    else:
        os.system(f"echo 'TEST #{test_case + 1}: OK'")
