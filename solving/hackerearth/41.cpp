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
const int N = 5e5 + 5;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int a0, a1, c, n;
		cin >> a0 >> a1 >> c >> n;
		vector<int> a(n);
		a[0] = a0, a[1] = a1;
		for (int i = 2; i < n; i++) {
			a[i] = c * a[i-1] + a[i-2];
			a[i] %= 10;
		}
		const int MOD = 41;
		int val = 0;
		for (int d : a) {
			val = val * 10 + d;
			val %= MOD;
		}
		cout << (val == 0 ? "YES\n" : "NO\n");
	}
}

