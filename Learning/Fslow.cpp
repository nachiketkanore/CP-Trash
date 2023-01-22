/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 03 August 2021 08:23:20 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
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

const int N = 5e5 + 5;
int n, A[N];

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		F0R(i, n) cin >> A[i];
		auto get_a = [&](int steps) {
			vector<int> ret;
			F0R(i, n) {
				int get = A[i];
				int cnt = steps;
				int j = i + 1;
				while (cnt--) {
					j %= n;
					get = __gcd(get, A[j]);
					j++;
				}
				ret.push_back(get);
			}
			return ret;
		};

		int lo = 0, hi = n;
		int ans = -1;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			vector<int> a_dash = get_a(mid);
			sort(ALL(a_dash));
			bool ok = a_dash.front() == a_dash.back();

			if (ok)
				ans = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}

		assert(~ans);
		cout << ans << '\n';
	}
}
