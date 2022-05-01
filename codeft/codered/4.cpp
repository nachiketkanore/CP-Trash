#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MX = 1e6 + 6;
const int INF = 1e12;
int N, M, A[MX + 1], B[MX + 1], C[MX + 1], ans[MX + 1], sum = 0;
int prefB[MX + 1];
int seg[5 * MX];

void update(int u, int tl, int tr, int id, int val) {
	if (tl > tr)
		assert(false);
	if (tl == tr) {
		assert(tl == id);
		// cout << "updated id = " << id << " val = " << val << endl;
		seg[tl] = min(seg[tl], val);
		return;
	}
	int mid = (tl + tr) / 2;
	if (id <= mid) {
		update(2 * u, tl, mid, id, val);
	} else {
		update(2 * u + 1, mid + 1, tr, id, val);
	}
	seg[u] = min(seg[2 * u], seg[2 * u + 1]);
}

int query(int u, int tl, int tr, int ql, int qr) {
	if (tr < ql || qr < tl || tl > tr || ql > qr)
		return INF;
	assert(tl <= tr && ql <= qr);
	if (ql <= tl && tr <= qr) {
		// cout << "taking " << ql << " " << qr << endl;
		return seg[u];
	}
	int mid = (tl + tr) / 2;
	int left = query(2 * u, tl, mid, ql, min(mid, qr));
	int right = query(2 * u + 1, mid + 1, tr, max(mid + 1, ql), qr);
	return min(left, right);
}

void upd(int id, int val) {
	update(1, 1, MX, id, val);
}

int qry(int L, int R) {
	if (L <= 0)
		L = 1;
	return query(1, 1, MX, L, R);
}

int32_t main() {
	cin >> N >> M;
	for (int i = 0; i < 4 * MX; i++) {
		// upd(i, INF);
		seg[i] = INF;
		if (i < MX) {
			ans[i] = INF;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		int u;
		cin >> u;
		prefB[u]++;
	}

	int MAX = 20;
	for (int i = 0; i < M; i++) {
		cin >> C[i];
		upd(C[i], C[i]);
		MAX = max(MAX, C[i]);
	}
	for (int i = 1; i <= MAX; i++) {
		prefB[i] += prefB[i - 1];
	}
	for (int i = 1; i <= MAX; i++) {
		int prev = 1;
		int becomes = 1;
		for (int mul = i; mul <= MAX; mul += i) {
			bool has = (prefB[mul] - prefB[prev - 1]) > 0;
			// for (int b = prev; b <= mul; b++) {
			// 	has |= B[b] > 0;
			// }
			if (has) {
				for (int c = prev; c <= mul; c++) {
					if (C[c] > 0)
						ans[i] = min(ans[i], becomes * c);
				}
				// cout << prev << ' ' << mul << " --> " << qry(prev, mul) << endl;
				// cout << i << ' ' << prev << ' ' << mul << " --> " << qry(prev, mul) << endl;
				// int best_c = qry(prev, mul);
				// if (best_c < INF) {
				//     ans[i] = min(ans[i], becomes * best_c);
				// }
			}
			becomes++;
			prev = mul + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		sum += ans[A[i]];
	}
	cout << sum;
	return 0;
}
