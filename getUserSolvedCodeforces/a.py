import requests

handle = input("Enter handle: ")
res = requests.get('https://codeforces.com/api/user.status?handle={}'.format(handle))

res = res.json()
if 'result' not in res:
	print("Invalid username")
	exit(0)

def my_problems():
	my = open("my.txt","r")
	ret = []
	for p in my:
		get = p.split('\n')[0]
		ret.append(get)
	return ret
	
res = res['result']
problems = []

for x in res:

	if 'problem' not in x:
		continue
	if 'index' not in x['problem']:
		continue
	if 'contestId' not in x:
		continue 

	index = x['problem']['index']
	contest = x['contestId']


	link = 'https://codeforces.com/problemset/problem/{}/{}'.format(contest, index)


	if len(str(contest)) > 4:
		link = 'https://codeforces.com/gym/{}/problem/{}'.format(contest, index)

	problems.append(link)

hisProblems = set(problems)
myProblems = my_problems()
myProblems = set(myProblems)

toSolve = hisProblems - myProblems
toSolve = set(toSolve)

fileName = "to_solve_problems_" + handle + ".txt"
file = open(fileName, "w")

for p in toSolve:
	file.write(p)
	file.write("\n")

file.close()

print ("All to_solve problems stored in {}".format(fileName))
print ("Total to solve with {} = {}".format(handle, len(toSolve)))
