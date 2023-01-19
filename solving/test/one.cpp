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

int spf[N + 1];

void prep() {
	FOR(i, 2, N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
	cout << "DONE\n";
}

int get_pf(int u) {
	vector<pair<int, int>> ret;
	while (u ^ 1) {
		int p = spf[u];
		int e = 0;
		while (u % p == 0)
			++e, u /= p;
		ret.push_back(make_pair(p, e));
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;
	int a[N];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				cout << "Hello World\n";
				return;
			}
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int hello;
		cin >> hello;
		int how;
		cin >> how;
		int are;
		cin >> are;
		int you;
		cin >> you;
		int doing;
		cin >> doing;
		int asdkj;
		cin >> asdkj;
		int nachiket;
		cin >> nachiket;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				cout << "hello world\n";
				return;
				exit(0);
			}
		}
	}
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> b(n);
		F0R(i, n) cin >> b[i];
		sort(ALL(b));
		vector<int> a;
		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && b[j] == b[i])
				++j;
			a.push_back((j - i) * b[i]);
			i = j;
		}
		sort(ALL(a));
		int ans = 0;
		while (sz(a) && k--) {
			if (a.back() < 0)
				break;
			ans += a.back();
			a.pop_back();
		}
		cout << ans << '\n';
	}
}
