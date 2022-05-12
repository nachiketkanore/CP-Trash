/**
 *    Author: Nachiket Kanore
 *    Created: Friday 13 May 2022 12:21:17 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 4e6;
bool marked[_];
int t[_];

void push(int v) {
	if (marked[v]) {
		t[v * 2] = t[v * 2 + 1] = t[v];
		marked[v * 2] = marked[v * 2 + 1] = true;
		marked[v] = false;
	}
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
	if (l > r)
		return;
	if (l == tl && tr == r) {
		t[v] = new_val;
		marked[v] = true;
	} else {
		push(v);
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm), new_val);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
	}
}

int get(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		return t[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return get(v * 2, tl, tm, pos);
	else
		return get(v * 2 + 1, tm + 1, tr, pos);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<array<int, 3>> Q(M);
	for (auto& [L, R, X] : Q) {
		cin >> L >> R >> X;
	}
	reverse(ALL(Q));
	for (auto& [L, R, X] : Q) {
		if (L <= X && X <= R) {
			update(1, 1, N, L, X - 1, X);
			update(1, 1, N, X + 1, R, X);
		} else {
			update(1, 1, N, L, R, X);
		}
	}
	FOR(i, 1, N) {
		cout << get(1, 1, N, i) << " \n"[i == N];
	}
	return 0;
}
