#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 5e5 + 5;

int n, Q, a[N];

struct FenwickTree {
	int n;
	vector<int> bit;
	FenwickTree(int n) : n(n) {
		bit = vector<int>(n + 1);
	}
	void add(int id, int val) {
		for (; id <= n; id += id & -id)
			bit[id] += val;
	}
	void add(int L, int R, int val) {
		add(L, val);
		add(R + 1, -val);
	}
	int get(int id) {
		int ret = 0;
		for (; id >= 1; id -= id & -id)
			ret += bit[id];
		return ret;
	}
};

int32_t main() {
	cin >> n >> Q;
	FenwickTree one(n), two(n), three(n);
	FOR(i, 1, n) cin >> a[i];
	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int L, R, X;
			cin >> L >> R >> X;
			one.add(L, R, 1);
			two.add(L, R, (X - L) * (X - L));
			three.add(L, R, 2 * (X - L));
		} else {
			int id;
			cin >> id;
			int ans = a[id] + id * id * one.get(id) + two.get(id) + id * three.get(id);
			cout << ans << '\n';
		}
	}
}
