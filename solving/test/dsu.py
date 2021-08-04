# Implementing DSU (Disjoint Set Union) - Generic type

class DSU():
    def __init__(self, n):
        # Using 0 bases indexing
        self.par = [i for i in range(n)]
        self.rank = [1 for i in range(n)]
        self.connected = n
    
    def find(self, u):
        if self.par[u] == u:
            return u
        self.par[u] = find(par[u])
        return self.par[u]

    def unite(self, u, v):
        assert (u >= 0 and u < n and v >= 0 and v < n)
        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False
        if self.rank[u] > self.rank[v]:
            swap(u, v)
        self.par[u] = v
        self.rank[v] += self.rank[u]
        self.rank[u] = 0
        self.connected -= 1

        return True

def main():
    n = 20
    dsu = DSU(n)
    print('All OK')

if __name__ == '__main__':
    main()
