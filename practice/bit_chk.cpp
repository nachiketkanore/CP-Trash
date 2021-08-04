#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int nn) {
        this->n = nn;
        bit.assign(nn, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void add(int L, int R, int delta) {
    	add(L, delta);
    	if (R + 1 < n)
    		add(R + 1, -delta);
    }
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	FenwickTree tree(n);

	for (int i = 0; i < n; i++) {
		int u;	cin >> u;
		a[i] = u;
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int t;	cin >> t;
		if (t == 1) {
			int L, R, val;
			cin >> L >> R >> val;
			--L, --R;
			tree.add(L, R, val);
		} else {
			int id;	
			cin >> id;
			--id;
			int ans = a[id] + tree.sum(id);
			cout << ans << '\n';
		}
	}
}