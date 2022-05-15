/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 15 May 2022 07:58:24 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 5e5 + 5;
int Q;
vector<int> A;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Q;
	while (Q--) {
		int type, x, y;
		cin >> type >> x;
		if (type == 1) {
			A.push_back(x);
		} else {
			cin >> y;
			for (int& a : A) {
				if (a == x)
					a = y;
			}
		}
	}
	for (int x : A) {
		cout << x << " ";
	}
	return 0;
}
