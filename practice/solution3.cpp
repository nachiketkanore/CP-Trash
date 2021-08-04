#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;

	int start = 0;
	int id = 0;
	while (id < sz(s) && s[id] == '0') {
		++start;
		++id;
	}	
	if (start == sz(s)) {
		cout << -1;
		return 0;
	}
	int last = 0;
	id = sz(s) - 1;
	while (id >= 0 && s[id] == '0') {
		--id;
		++last;
	}
	int ans = start + last;

	int curr = 0;
	for (char ch : s) {
		if (ch == '0') {
			++curr;
			ans = max(ans, curr);
		} else {
			ans = max(ans, curr);
			curr = 0;
		}
	}
	ans = max(ans, curr);
	cout << ans;
}