/**
 *    Author: Nachiket Kanore
 *    Created: Friday 07 October 2022 09:24:51 PM IST
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

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

void solve(int tc) {
	int N;
	cin >> N;
	vector<pair<int, int>> A(3);
	for (auto& [x, y] : A) {
		cin >> x >> y;
	}
	int X, Y;
	cin >> X >> Y;

	auto inside = [&](int x, int y) { return 1 <= x && x <= N && 1 <= y && y <= N; };

	int which = -1;
	F0R(i, 3) {
		vector<pair<int, int>> other;
		F0R(j, 3) if (i ^ j) other.push_back(A[j]);
		sort(ALL(other));
		int x = A[i].first, y = A[i].second;
		F0R(id, 4) {
			int nx1 = x + dx[id], ny1 = y + dy[id];
			int nx2 = x + dx[(id + 1) % 4], ny2 = y + dy[(id + 1) % 4];
			if (inside(nx1, ny1) && inside(nx2, ny2)) {
				vector<pair<int, int>> chk = { make_pair(nx1, ny1), make_pair(nx2, ny2) };
				sort(ALL(chk));
				if (other == chk) {
					which = i;
					break;
				}
			}
		}
		if (~which)
			break;
	}
	assert(~which);
	// see(tc, A[which]);
	bool found = false;

	int x = A[which].first, y = A[which].second;
	if ((x == 1 && y == 1) || (x == 1 && y == N) || (x == N && y == 1) || (x == N && y == N)) {
		found |= x == X;
		found |= y == Y;
	} else {
		found |= x % 2 == X % 2;
		found |= y % 2 == Y % 2;
	}
	/* found |= x == X;
	found |= y == Y;

	F0R (id, 4) {
		int nx = x + dx[id], ny = y + dy[id];
		if (inside(nx, ny)) {
			found |= nx + ny == X + Y;
			found |= nx - ny == X - Y;
		}
	} */

	cout << (found ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		solve(tc);
	}

	return 0;
}
