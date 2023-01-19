/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 05 August 2021 01:11:26 AM IST
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

const int N = 2e5 + 5;
int n, q, bit[26][N];

void upd(int w, int id, int val) {
	while (id < N) {
		bit[w][id] += val;
		id += id & -id;
	}
}

int pref(int w, int id) {
	int ret = 0;
	while (id > 0) {
		ret += bit[w][id];
		id -= id & -id;
	}
	return ret;
}

int32_t main() {
	string s;
	cin >> s;
	n = sz(s);
	s = "#" + s;
	FOR(i, 1, n) {
		int ch = s[i] - 'a';
		upd(ch, i, 1);
	}
	cin >> q;
	while (q--) {
		int k;
		char ch;
		cin >> k >> ch;
		int w = ch - 'a';

		int lo = 1, hi = n;
		int ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (pref(w, mid) >= k)
				ans = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		if (~ans) {
			upd(w, ans, -1);
		}
	}
	FOR(i, 1, n) {
		string poss;
		F0R(ch, 26) if (pref(ch, i) - pref(ch, i - 1)) poss += char(ch + 'a');
		assert(sz(poss) <= 1);
		if (sz(poss))
			cout << poss.back();
	}
	cout << '\n';
}
