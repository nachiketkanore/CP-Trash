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

bool check_prime(int u) {
	if (u < 2) return false;
	for (int d = 2; d * d <= u; d++) if (u % d == 0) return false;
	return true;
}

int32_t main() {
	int cnt = 0;
	FOR (i,1,50000) if (check_prime(i)) ++cnt;
	cout << cnt << endl;
}

