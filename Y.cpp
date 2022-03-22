#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
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

const int inf = 1e18;
const int N	  = 5e5 + 5;

void hello() {
	int hey;
	cin >> hey;
	cout << hey;
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	F0R(i, n) cin >> a[i];
	F0R(i, m) cin >> b[i];
	int G			= 0;
	F0R(i, n - 1) G = __gcd(G, abs(a[i] - a[i + 1]));
	F0R(i, m) {
		int A = a[0] + b[i];
		cout << __gcd(A, G) << " \n"[i + 1 == m];
	}
}

