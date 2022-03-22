/**
 *    Author: Solve Machine
 *    Created: Tuesday 22 March 2022 08:03:26 PM IST
**/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
	int n, B, x, y;
	cin >> n >> B >> x >> y;
	int prev = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		int c1 = prev + x;
		int c2 = prev - y;
		if (c1 <= B) {
			prev = c1;
			sum += c1;
		} else if (c2 <= B) {
			prev = c2;
			sum += c2;
		} else {
			assert(0);
		}
	}
	cout << sum << '\n';
}

int32_t main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
}
