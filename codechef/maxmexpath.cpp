/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 10:14:59 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int _ = 1e5 + 5;
int N, A[_], cnt[_], ans;
vector<int> g[_];

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    void init(int n) {
        this->n = n + 5;
		bit = vector<int> (this->n, 0);
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
} values;

void dfs(int u, int par) {
	cnt[A[u]]++;
	if (cnt[A[u]] == 1) {
		values.add(A[u], +1);
	}
	int mex = -1;
	int lo = 0, hi = N;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (values.sum(mid) != mid + 1) {
			mex = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	assert(~mex);
	ans = max(ans, mex);
	for (int v: g[u]) {
		if (v^par) {
			dfs(v, u);
		}
	}
	cnt[A[u]]--;
	if (cnt[A[u]] == 0) {
		values.add(A[u], -1);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		values.init(N);
		ans = 0;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
		}
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		cout << ans << '\n';
		for (int i = 1; i <= N; i++) {
			cnt[A[i]] = 0;
			g[i].clear();
		}
	}
	return 0;
}
