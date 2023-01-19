#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 8e5 + 5;

int n, k, l[N], r[N], passing[N], starting[N], mx;
vector<int> pts;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) {
			p *= q;
			p %= m;
		}
		q *= q;
		q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long mod = 998244353;
long long fact[N], factinv[N]; // less than 1e6

void init(int N) {
	fact[0] = 1;
	for (int i = 1; i <= N; i++)
		fact[i] = (1LL * i * fact[i - 1]) % mod;
	for (int i = 0; i <= N; i++)
		factinv[i] = Div(1, fact[i], mod);
}

long long ncr(long long n, long long r) {
	if (r > n)
		return 0;
	return (fact[n] * factinv[r] % mod) * factinv[n - r] % mod;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init(N - 2);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		pts.push_back(l[i]);
		pts.push_back(r[i]);
	}
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());

	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(pts.begin(), pts.end(), l[i]) - pts.begin();
		r[i] = lower_bound(pts.begin(), pts.end(), r[i]) - pts.begin();
		assert(l[i] <= r[i]);
		mx = max(mx, r[i]);
		passing[l[i]]++;
		passing[r[i] + 1]--;
		starting[l[i]]++;
	}

	for (int i = 1; i < N; i++) {
		passing[i] += passing[i - 1];
		assert(passing[i] >= starting[i]);
	}

	int ans = 0;

	for (int x = 0; x <= mx; x++)
		if (starting[x] > 0) {
			int start = starting[x];
			int non_start = passing[x] - start;

			// We want to choose k segments, say `take` from start and `k - take` from non_start
			for (int take = 1; take <= start; take++)
				if (k - take >= 0) {
					ans = (ans + ncr(start, take) * ncr(non_start, k - take)) % mod;
				}
		}

	cout << ans;
}