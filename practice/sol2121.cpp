#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e18;

int tree[4 * N];
int n;	

void update(int tl, int tr, int node, int id, int val) {
	if (tl > tr) return;
	if (tl == tr) {
		tree[node] = val;
		return;
	}
	int mid = (tl + tr) >> 1;
	if (id <= mid) 
		update(tl, mid, 2 * node, id, val);
	else 
		update(mid + 1, tr, 2 * node + 1, id, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr) return inf;
	if (tl == ql && tr == qr) 
		return tree[node];
	int mid = (tl + tr) >> 1;
	int left = query(tl, mid, 2 * node, ql, min(qr, mid));
	int right = query(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);
	return min(left, right);
}

void put(int id, int val) {
	update(1, n, 1, id, val);
}

int get(int L, int R) {
	return query(1, n, 1, L, R);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	FOR(i,0,4*N-1) tree[i] = inf;

	cin >> n;

	FOR(i,1,n) {
		int u;	cin >> u;
		put(i, u);
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int t;	cin >> t;
		if (t == 1) {
			int id, val;
			cin >> id >> val;
			put(id, val);
		} else {
			int L, R;
			cin >> L >> R;
			cout << get(L, R) << '\n';
		}
	}
}