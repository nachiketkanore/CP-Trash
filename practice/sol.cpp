#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int info[1005];
int n, k, mod;
int pow10[1005];
int dp[2][1005][105];

int power(int a, int b, int mod) {
	assert(a == 10);
	return pow10[b];
}

void pre() {
	info[0] = 1 % mod;
	info[1] = 9 % mod;
	pow10[0] = 1 % k;
	pow10[1] = 10 % k;
	for (int i = 2; i < 1002; i++) {
		info[i] = (info[i - 1] * 10) % mod;
		pow10[i] = (pow10[i - 1] * 10) % k;
	}
}

// 1234 = next_digit * power(10, 2) + 34

int go(int id, int modulo, bool taken) {
	if (modulo == 0 && id != 1 && taken) {
		int remaining = n - (id - 1);
		return info[remaining];
	}
	if (id > n)
		return 0;
	int& ans = dp[taken][id][modulo];
	if (~ans)
		return ans;
	ans = 0;

	int start = ;

	for (int d = (id == n ? 1 : 0); d < 10; d++) {
		int next_modulo = d * pow10[id - 1] + modulo;
		next_modulo %= k;
		ans = (ans + go(id + 1, next_modulo, taken | (d != 0))) % mod;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> mod;
	pre();
	memset(dp, -1, sizeof(dp));
	cout << go(1, 0, 0);
}