#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, k;
string s;
int freq[26][N];

int get_freq(int L, int R, char ch) {
	return freq[ch - 'a'][R] - freq[ch - 'a'][L - 1];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	cin >> s;
	s = " " + s;

	FOR(i, 1, n) {
		freq[s[i] - 'a'][i]++;
		for (char ch : { 'a', 'b' }) {
			freq[ch - 'a'][i] += freq[ch - 'a'][i - 1];
		}
	}

	int ans = 0;

	FOR(i, 1, n) {
		int lo = i, hi = n;
		int right = i;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int fa = get_freq(i, mid, 'a');
			int fb = get_freq(i, mid, 'b');
			int change = min(fa, fb);
			if (change <= k) {
				right = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		ans = max(ans, right - i + 1);
	}
	cout << ans;
}