/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 04 September 2021 03:05:19 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int int64_t
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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, X;
		cin >> N >> X;
		vector<int> A(N);
		F0R(i, N) cin >> A[i];
		sort(ALL(A));
		if (X == 0) {
			int req = 0;
			int best = 0;
			for (int i = 0; i < N;) {
				int j = i, len = 0;
				while (j < N && A[j] == A[i])
					++j, ++len;
				cmax(best, len);
				i = j;
			}
			cout << best << ' ' << req << '\n';
		} else {
			int best = -1, req = -1;
			map<int, int> f;
			for (int x : A)
				f[x]++;
			for (auto [val, freq] : f) {
				int other = val ^ X;
				assert(other ^ val);
				int tot = f[other] + freq;
				if (tot > best) {
					best = tot;
					req = f[other];
				} else if (tot == best) {
					cmin(req, f[other]);
				}
			}
			assert(~best);
			assert(~req);
			cout << best << ' ' << req << '\n';
		}
	}
}
