MOD = 10 ** 9 + 7
def go(i, j, k, p_taken, q_taken, p, q, r, n, m, r_size, ANS = []):
    if(k == r_size):
        if(p_taken and q_taken):
            print(ANS)
            return 1
        else:
            return 0

    c1 = 0
    c2 = 0
    if(i < n):
        if(p[i] == r[k]):
            c1 = go(i+1, j, k+1, True, q_taken, p, q, r, n, m, r_size, ANS + [-i])

        else:
            c1 = go(i+1, j, k, p_taken, q_taken, p, q, r, n, m, r_size, ANS)

    if(j < m):
        if(q[j] == r[k]):
            c2 = go(i, j+1, k+1, p_taken, True, p, q, r, n, m, r_size, ANS + [j])

        else:
            c2 = go(i, j+1, k, p_taken, q_taken, p, q, r, n, m, r_size, ANS)

    return (c1+c2) % MOD

p = input()
q = input()
r = input()

print(go(0, 0, 0, 0, 0, p, q, r, len(p), len(q), len(r)))
