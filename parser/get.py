#!/usr/bin/python2
 
from __future__ import print_function
import re
import requests
import sys
import os
 
if len(sys.argv) < 2:
    print ("Need contest number")
    sys.exit(0)
 
number = sys.argv[1]
 
def parse_task(index):
    r = requests.get("http://codeforces.com/contest/" + number + "/problem/" +
                     index)
    s = r.text
    a = re.findall("Input</div><pre>.*?</pre>", s)
    b = re.findall("Output</div><pre>.*?</pre>", s)
 
    if (len(a) == 0):
        print ("Something went wrong...")
        sys.exit(0)
 
    assert(len(a) == len(b))
    for i in range(len(a)):
        a[i] = a[i][16:-6].replace('<br />', '\n')
        b[i] = b[i][17:-6].replace('<br />', '\n')

    os.system("mkdir {}".format(index))
    os.system("cp ~/CP/template.cpp {}/sol.cpp".format(index))
    os.system("cp ~/CP/gen.cpp {}/".format(index))
    os.system("cp ~/CP/stress.sh {}/".format(index))
    os.system("cp ~/CP/check.sh {}/".format(index))

    for i in range(len(a)):
        with open(index + "/in" + str(i) + ".in", "w") as f:
        	print(a[i], end="", file=f)
        with open(index + "/out" + str(i) + ".out", "w") as f:
        	print(b[i], end="", file=f)
# print >> f, a[i]
# print >> f, b[i]
 	    
r = requests.get("http://codeforces.com/contest/" + number)
s = r.text
a = re.findall("/contest/" + number + "/problem/.", s)
a = sorted(list(set(a)))
print ('total = {}'.format(len(a)))


for x in a:
    print (x)
    parse_task(x[-1])
