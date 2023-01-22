/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 07 August 2021 05:14:09 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

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

bool check_odd(int n) {
	for (int i = 1; i < 32; i += 2) {
		if ((1LL << i) == n)
			return true;
	}
	return false;
}

bool check_all_odd(int n) {
	for (int i = 0; i < 32; i += 2) {
		if (n >> i & 1LL)
			return false;
	}
	return true;
}

int32_t main() {
	srand(time(0));
	int T = 1000;
	cin >> T;
	while (T--) {
		const int LOG = 32;
		int n = rand() % 10 + 1, x = rand() % 10 + 1;
		cin >> n >> x;

		vector<int> even, odd;

		F0R(j, LOG) {
			if (n >> j & 1LL) {
				if (j % 2 == 0)
					even.push_back(j);
				else
					odd.push_back(j);
			}
		}

		if (x == 0 && n % 2 == 1) {
			cout << "-1\n";
			continue;
		}

		sort(ALL(even));
		sort(ALL(odd));

		const int inf = 1e12;
		int ans = inf;

		FOR(cnt_even, 0, sz(even)) {

			FOR(cnt_odd, 0, sz(odd)) {

				int first = 0;
				F0R(j, sz(even)) {
					if (j < cnt_even)
						first += 1ll << even[j];
				}

				F0R(j, sz(odd)) {
					if (j < cnt_odd)
						first += 1ll << odd[j];
				}

				if ((first <= x || (check_odd(first)))) {
					see(cnt_even, cnt_odd, first);
					// assert(first >= 1);
					int req = (first > 0) + 2 * (sz(even) - cnt_even) + (sz(odd) - cnt_odd);
					cmin(ans, req);
				}
			}
		}

		if (ans >= inf) {
			see(n, x);
			see(even, odd);
			assert(false);
			ans = -1;
		}
		cout << ans << '\n';
	}
	// see("---\n");
}
