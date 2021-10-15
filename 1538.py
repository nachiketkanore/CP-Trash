T = int(input())

for _ in range(T):
    N = int(input())
    memo = {}
    last = ''
    for i in range(N):
        S = input()
        if ':' in S:
            S = S.split(' := ')
            # X = Y
            X, Y = S
            memo[X] = Y
            last = X
        else:
            S = S.split(' = ')
            # X = Y + Z
            X = S[0]
            Y, Z = S[1].split(' + ')
            memo[X] = memo[Y] + memo[Z]
            last = X
    chk = memo[last]
    ans = chk.count('haha')
    print(ans)
