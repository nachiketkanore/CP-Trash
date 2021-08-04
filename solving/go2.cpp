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
		int n;
		cin >> n;
		if (n % 3 == 0) {
			cout << n << '\n';
			continue;
		}
		int ans = inf;
		string s = to_string(n);
		F0R (pos,n+1) {
			string t;
			F0R (i,pos) t += s[i];
			string w;
			if (pos < sz(s)) w = s.substr(pos);
			F0R (dig,10) {
				string get = t + to_string(dig) + w;
				int val = stoll(get);
				if (val % 3 == 0) cmin(ans, val);
			}
		}
		assert(ans ^ inf);
		cout << ans << '\n';
	}
}

