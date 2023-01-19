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

int solve(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> A(n);
	for (int& x : A)
		cin >> x;
	int x;
	cin >> x;
	return (int)sqrtl(x);
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		F0R(i, n) cin >> a[i];
		F0R(i, n) cin >> b[i];
		sort(ALL(a));
		sort(ALL(b));
		vector<int> ans(n);
		F0R(i, n) ans[i] = a[i] + b[i];
		for (int& x : ans)
			cout << x << ' ';
		cout << '\n';
	}
}
