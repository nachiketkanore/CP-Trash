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

vector<int> test(int u) {
	vector<int> pfs;
	for (int i = 2; i * i <= u; i++) {
		if (u % i == 0) {
			pfs.push_back(i);
			while (u % i == 0)
				u /= i;
		}
	}
	if (u > 1)
		pfs.push_back(u);
	return pfs;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		const int n = sz(s);
		bool yes = true;
		for (char want = (char)('a' + n - 1); want >= 'a'; want--) {
			if (s.front() == want)
				s = s.substr(1);
			else if (s.back() == want)
				s = s.substr(0, sz(s) - 1);
			else
				yes = false;
		}
		cout << (yes ? "YES\n" : "NO\n");
	}
}
