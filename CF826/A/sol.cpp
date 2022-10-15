/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 11 October 2022 08:06:47 PM IST
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

void print(char ch) {
	cout << ch << '\n';
}

void solve() {
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "=" << '\n';
		return;
	}
	char x = a.back();
	char y = b.back();
	int cx = 0, cy = 0;
	int id = 0;
	while (id < sz(a) && a[id] == 'X')
		++cx, id++;
	id = 0;
	while (id < sz(b) && b[id] == 'X')
		++cy, id++;

	// see(a, b, cx, cy);

	if (x == y) {
		if (cx == cy) {
			print('=');
		} else if (cx > cy) {
			if (x == 'S')
				print('<');
			else if (x == 'L')
				print('>');
		} else {
			if (x == 'S')
				print('>');
			else if (x == 'L')
				print('<');
		}
	} else {
		if (x == 'S' && y == 'M') {
			print('<');
			return;
		}
		if (x == 'M' && y == 'S') {
			print('>');
			return;
		}
		if (x == 'S' && y == 'L') {
			print('<');
			return;
		}
		if (x == 'L' && y == 'S') {
			print('>');
			return;
		}
		if (x == 'M' && y == 'L') {
			print('<');
			return;
		}
		if (x == 'L' && y == 'M') {
			print('>');
			return;
		}
		assert(false);
	}
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
