#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int k) {
	const int n = a.size();
	vector<int> pref(n), suff(n);
	for (int i = 0; i < n; i++) {
		if (a[i] < k)
			pref[i] = -1;
		else if (a[i] > k)
			pref[i] = +1;
		else
			pref[i] = 0;
		suff[i] = pref[i];
		if (i)
			pref[i] += pref[i - 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		suff[i] += suff[i + 1];
	}
	int ans = 0;
	for (int L = 0; L < n; L++) {
		if (pref[L] == 0)
			ans = max(ans, L + 2);
		if (suff[L] == 0)
			ans = max(ans, n - L);
		for (int R = L + 1; R < n; R++) {
			if (pref[L] + suff[R] == 0)
				ans = max(ans, L + 1 + n - R);
		}
	}
	return ans;
}

int main() {
	vector<int> a = { 1, 2, 3 };
	int k = 4;
	cout << solve(a, k) << endl;
}
