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
const int N = 5e5 + 5;

int nachiket() {
	int x;
	cin >> x;
	return x;
}

void main2() {
	int x;
	cin >> x;
	F0R(i, n) cin >> a[i];
	int prefix_sums, suffix_sums;
	for (int i = 0; i < n; i++) {
		prefix_sums += a[i];
		pref[i] = prefix_sums;
		int x;
		cin >> x;
	}
}

void pre() {
	int n;
	cin >> n;
	vector<int> a(n);
	F0R(i, n) cin >> a[i];
	size_t f = 0;
	for (f = 0; f < n; f++) {
		if (f > 0) {
			a[f] += a[f - 1];
		} else {
			if (true) {
				nachiket;
				kanore;
			} else {
				int hello;
				cin >> hello;
			}
		}
	}
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, sum = 0;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) {
			cin >> x;
			sum += x;
		}
		if (sum % n)
			cout << "-1\n";
		else {
			int each = sum / n;
			int ans = 0;
			for (int& x : a)
				ans += x > each;
			cout << ans << '\n';
		}
	}
}
