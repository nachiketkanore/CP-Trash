/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 05 May 2024 11:27:35 PM IST
 **/
#include "bits/stdc++.h"
#include <cstdint>
#include <functional>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

int N, M;
int mat[100][100];
int8_t cache[100][100];

void solve() {
	cin >> N >> M;
	F0R(i, N) F0R(j, M) cin >> mat[i][j];

	function<bool(int, int, int)> path_present = [&](int i, int j, int want) -> bool {
		if (i < 0 || i >= N || j < 0 || j >= M) {
			return false;
		}
		if (mat[i][j] % want) {
			return false;
		}
		if (~cache[i][j])
			return cache[i][j];
		if (i == N - 1 && j == M - 1) {
			return true;
		}
		return cache[i][j] = path_present(i + 1, j, want) | path_present(i, j + 1, want);
	};

	auto check = [&](int want) {
		F0R(i, N) F0R(j, M) cache[i][j] = -1;
		return path_present(0, 0, want);
	};

	int D = __gcd(mat[0][0], mat[N - 1][M - 1]);
	vector<int> divisors;
	for (int d = 1; d * d <= D; d++) {
		if (D % d == 0) {
			divisors.push_back(d);
			if (D / d != d)
				divisors.push_back(D / d);
		}
	}
	sort(ALL(divisors));
	reverse(ALL(divisors));
	int ans = 0;
	for (int d : divisors) {
		if (check(d)) {
			ans = d;
			break;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
