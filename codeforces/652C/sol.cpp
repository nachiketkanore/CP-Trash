/**
 *    Author: Nachiket Kanore
 *    Created: Friday 07 June 2024 10:27:10 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 3e5 + 5;
int N, M, P[_], index_of[_], edge_right[_];
pair<int, int> F[_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> P[i];
		index_of[P[i]] = i;
		edge_right[i] = N + 1;
	}
	FOR(i, 1, M) cin >> F[i].first >> F[i].second;
	FOR(i, 1, M) {
		auto [a, b] = F[i];
		if (index_of[a] > index_of[b]) {
			swap(a, b);
		}
		edge_right[index_of[a]] = min(edge_right[index_of[a]], index_of[b]);
	}

	int answer = 0;
	int min_edge_right = N + 1;

	for (int R = N; R; --R) {
		min_edge_right = min(min_edge_right, edge_right[R]);
		answer += min_edge_right - R;
	}

	cout << answer << '\n';

	return 0;
}
