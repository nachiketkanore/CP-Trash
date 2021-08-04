#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

vector<array<int,3>> ans;
vector<int> a;

void move(int i, int j, int x) {

	a[i] -= x * i;
	a[j] += x * i;
	assert(a[i] >= 0);
	ans.push_back({i, j, x});
}

void solve() {
	int n;
	cin >> n;
	a.resize(n + 1);
	int sum = 0;
	FOR(i,1,n) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n != 0) {
		cout << -1 << '\n';
		return;
	}

	ans.clear();

	FOR(i,2,n) {
		if (a[i] % i == 0) {
			int x = a[i] / i;
			move(i, 1, x);
		} else {
			int extra = i - (a[i] % i);
			move(1, i, extra);
			assert(a[i] % i == 0);
			int x = a[i] / i;
			move(i, 1, x);
		}
	}

	assert(a[1] == sum);
	FOR(i,2,n) move(1, i, sum/ n);
	FOR(i,1,n) assert(a[i] == sum/n);
	assert(sz(ans) <= 3 * n);

	cout << sz(ans) << '\n';
	for (array<int,3> x : ans) {
		cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();	
}