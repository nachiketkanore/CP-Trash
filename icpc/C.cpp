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

const int N = 1e5 + 5;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n + 1);
		FOR(i, 1, n) {
			int len;
			cin >> len;
			FOR(j, 1, len) {
				int u;
				cin >> u;
				a[i].push_back(u);
			}
		}
		multiset<int> sizes;
		int ans = 0;
		FOR(i, 1, n) {
			bool sorted = true;
			for (int j = 1; j < sz(a[i]); j++) {
				sorted &= a[i][j] > a[i][j - 1];
			}
			if (sorted) {
				// see(a[i], "OK");
				sizes.insert(sz(a[i]));
				continue;
			}

			vector<int> parts;
			for (int j = 0; j < sz(a[i]);) {
				int cnt = 1, id = j + 1;
				while (id < sz(a[i]) && a[i][id - 1] < a[i][id]) {
					++cnt;
					id++;
				}

				parts.push_back(cnt);
				j = id;
			}
			int mx = parts.front(), sum = 0;
			for (int part : parts) {
				sum += part;
				cmax(mx, part);
			}

			for (int part : parts) {
				sizes.insert(part);
			}

			int req = sum - mx;
			ans += req;
			// see(a[i], parts, req);
		}

		while (sz(sizes) > 1) {
			int one = *sizes.begin();
			sizes.erase(sizes.find(one));
			int two = *sizes.begin();
			sizes.erase(sizes.find(two));
			ans += one + two;
			sizes.insert(one + two);
		}

		cout << ans << '\n';
	}
