/*
Author: Nachiket Kanore
Created: Saturday 12 December 2020 01:13:55 PM IST
(ツ) There is no duty we so underrate as the duty of being happy. By being happy we sow anonymous benefits upon the world.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		int n;	cin >> n;
		int l = 1;
		while (n--) {
			int u;	cin >> u;
			l = l * u / __gcd(l, u);
		}
		cout << l << "\n";
	}
}
