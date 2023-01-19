#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int n, freq[5][N], ans, p3[N];
string s;

int get_count(int L, int R, char ch) {
	if (L > R)
		return 0;
	if (ch >= 'a' && ch <= 'c')
		return freq[ch - 'a'][R] - freq[ch - 'a'][L - 1];
	return freq[3][R] - freq[3][L - 1];
}

int pow3(int x) {
	if (x < 0)
		return 0;
	return p3[x];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	p3[0] = 1;
	for (int i = 1; i < N; i++) {
		p3[i] = 3 * p3[i - 1] % mod;
	}

	cin >> n >> s;
	s = " " + s;

	// 0 for 'a', 1 for 'b', 2 for 'c' and '3' for '?'
	for (int i = 1; i <= n; i++) {
		if (s[i] != '?')
			freq[s[i] - 'a'][i]++;
		else
			freq[3][i]++;
		for (int j = 0; j < 4; j++) {
			freq[j][i] += freq[j][i - 1];
		}
	}

	for (int i = 1; i <= n; i++)
		if (s[i] == '?' || s[i] == 'b') {
			int q = get_count(1, i - 1, '?');
			int a = get_count(1, i - 1, 'a');
			int pref = a * pow3(q) + q * pow3(q - 1);
			pref %= mod;

			q = get_count(i + 1, n, '?');
			int c = get_count(i + 1, n, 'c');
			int suff = c * pow3(q) + q * pow3(q - 1);
			suff %= mod;
			ans = (ans + pref * suff) % mod;
		}

	cout << ans;
}