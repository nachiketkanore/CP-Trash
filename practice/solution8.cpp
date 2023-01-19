#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

vector<int> next_a(vector<int> a, int id) {
	if (id < 0 || id >= sz(a))
		assert(0);
	vector<int> ret;
	for (int i = 0; i < sz(a); i++)
		if (id != i)
			ret.push_back(a[i]);
	return ret;
}

int go(vector<int> a) {
	int ans = 0;

	// try to find atleast one losing state for opponent
	set<int> f(a.begin(), a.end());
	if (sz(f) == sz(a))
		return 1;

	for (int i = 0; i < sz(a); i++) {
		ans |= go(next_a(a, i)) == 0;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	if (go(a))
		cout << "First\n";
	else
		cout << "Second\n";
}