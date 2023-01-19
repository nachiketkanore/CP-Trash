#include <bits/stdc++.h>

using namespace std;

#define int int64_t
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = pow(10, 9) + 7;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define iterate(x) for (auto itr = x.begin(); itr != x.end(); ++itr)
ll myceil(ll a, ll b) {
	if (a % b == 0)
		return a / b;
	else
		return a / b + 1;
}
bool isPerSquare(long double a) {
	if (a < 0)
		return false;
	ll sr = sqrt(a);
	return (sr * sr == a);
}

ll arr1[200002];
ll arr2[200002];
int arr3[100];

void solve() {
	ll n, m, a, b, c, d;
	string s;

	cin >> n;
	forn(i, n) cin >> arr1[i];
	forn(i, n) cin >> arr2[i];
	forn(i, 31) arr3[i] = 0;

	forn(i, n) {
		ll temp = arr1[i], cnt = 0;
		if (arr1[i] == 0) {
			forn(j, 31) arr3[j]++;
			continue;
		}

		while (temp % 2 == 0) {
			cnt++;
			temp /= 2;
		}
		rforsn(j, cnt, 0) arr3[j]++;
	}

	ll nowremain = 0;

	sort(arr2, arr2 + n);

	// forsn(i,1,31) cout << arr3[i] << " ";

	ll ans = 1;

	rforn(i, n - 1) {
		ans = (ans * (arr3[arr2[i]] - nowremain)) % MOD;
		nowremain++;
	}
	int brute = 0;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		A[i] = arr1[i];
	sort(A.begin(), A.end());
	do {
		bool ok = true;
		for (int i = 0; i < n; i++) {
			ok &= A[i] % (1LL << arr2[i]) == 0;
		}
		brute += ok;
	} while (next_permutation(A.begin(), A.end()));
	if (ans == 0)
		ans = -1;
	if (brute == 0)
		brute = -1;
	assert(ans == brute);
	cout << ans << ' ' << brute << '\n';
}
int32_t main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	for (int it = 1; it <= t; it++) {
		// cout << "Case #" << it+1 << ": ";
		solve();
	}
	return 0;
}
