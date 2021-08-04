#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string x;
		cin >> x;
		vector<int> U, V;
		bool found = false;
		int big = -1;
		F0R (i,n) {
			int u = inf, v = inf;
			int want = x[i]-'0';
			F0R (one,3) F0R (two,3) if ((one + two) % 3 == want) {
				if (found) {
					if (big == 1) if (u >= one) u = one, v = two;
					else if (big == 2) if (v >= two) u = one, v = two;
					else assert(0);
				} else {
					if (max(one, two) <= max(u, v))
						u = one, v = two;
				}
			}
			U.push_back(u);
			V.push_back(v);
			if (u > v && !found) {
				found = true;
				big = 1;
			} else if (v > u && !found) {
				found = true;
				big = 2;
			}
		}
		for (int x: U) cout << x; cout << '\n';
		for (int x: V) cout << x; cout << '\n';
	}
}

