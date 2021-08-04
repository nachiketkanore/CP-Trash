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
const int N = 1e7 + 5;

int n, spf[N+1];

int32_t main() {
	FOR (i,2,N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
	cin >> n;
	vector<int> d1, d2;
	FOR (id,1,n) {
		int u;
		cin >> u;
		int val = u;
		vector<int> pf;
		while (u^1) {
			int p = spf[u];
			while (u % p == 0) u /= p;
			pf.push_back(p);
		}
		if (sz(pf) >= 2) {
			bool done = false;
			int left = 1, right = 1;
			F0R (i,sz(pf)) right *= pf[i];
			F0R (i,sz(pf)) {
				left *= pf[i];
				right /= pf[i];
				if (__gcd(left + right, val) == 1) {
					d1.push_back(left);
					d2.push_back(right);
					done = true;
					break;
				}
			}
			assert(done);	
		} else {
			d1.push_back(-1);
			d2.push_back(-1);
		}
	}
	for (int a : d1) cout << a << ' ';	cout << '\n';
	for (int a : d2) cout << a << ' ';	cout << '\n';
}

