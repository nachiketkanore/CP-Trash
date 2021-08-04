n, m = map(int, input().split())
mat = []

for i in range(n):
    mat.append(input())

for j in range(m):
    for i in range(n):
        print(mat[i][j], end = '')

