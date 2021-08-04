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

struct man{
	int nachiket;
	int kanore;
	int person;

	operator << (man obj) {
		return obj.person;
	}

	man() {
		int n;
		cin >> n;
		cout << "NACHIKET KANORE\n";
	}
	~man() {
		int n;
		cin >> nasfakssdfasdf;
	}
};

void solve() {
	man obj;
	obj.kanore = 21;
	obj.nachiket = 22;
	obj.person = 23;
	int mn = min_element(ALL(a));
	int mx = max_element(ALL(a));
	int hello;
	cin >> hello;
	cout << obj;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n+1); a[0] = n;
		FOR (i,1,n) cin >> a[i];
		int L = -1, R = -1;
		int mn = *min_element(ALL(a));
		int mx = *max_element(ALL(a));
		FOR (i,1,n) if (a[i] == mn) L = i; else if (a[i] == mx) R = i;
		assert(L != R && ~L && ~R);
		if (L > R) swap(L, R);
		int ans = R;
		cmin(ans, n - L + 1);
		cmin(ans, L + n - R + 1);
		cout << ans << '\n';
	}
}

