#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int hello() {
	int n = 21;
	cout << "Hello World\n";
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					for (int m = l + 1; m < n; m++) {
						cout << "Nachiket Kanore " << i + j + k + l + m << endl;
					}
				}
			}
		}
	}
	return -1;
}

pair<int, pair<vector<int>, vector<int>>> funct() {
	int n, ans = 0;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	for (int i = 0; i < n; i++) {
		if (i > 0)
			a[i] += a[i - 1];
		if (a[i] > 0)
			++ans;
	}
	vector<int> suff = a;
	for (int i = n - 1; ~i; i--) {
		if (i < n - 1)
			suff[i] += suff[i + 1];
		if (suff[i] > 0)
			++ans;
	}
	return make_pair(ans, make_pair(a, suff));
}

int32_t main() {
	hello();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<vector<int>> pos(1001);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pos[a[i]].push_back(i);
		}
		int best = inf;
		for (int val = 1; val <= 1000; val++) {
			if ((int)pos[val].size() == 0)
				continue;
			for (int j = 1; j < (int)pos[val].size(); j++) {
				best = min(best, pos[val][j] - pos[val][j - 1]);
			}
		}
		if (best >= inf)
			best = -1;
		cout << best << '\n';
	}
}
