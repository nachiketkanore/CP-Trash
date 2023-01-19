/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 April 2022 09:50:27 AM IST
 **/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int n = 4;
ll x[n], y[n], it[n];
tuple<ll, ll, ll> sol(ll a, ll b, ll c, ll d) {
	if (a > b)
		swap(a, b);
	if (c > d)
		swap(c, d);
	return { b + d - c - a, max({ 0ll, a - d, c - b }), max({ 0ll, b - c, d - a }) };
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i], it[i] = i;
		ll ret = 0x3f3f3f3f3f3f3f3f;
		do {
			ll a, b, c, d, f1, f2;
			tie(f1, a, b) = sol(x[it[0]], x[it[1]], x[it[2]], x[it[3]]);
			tie(f2, c, d) = sol(y[it[0]], y[it[2]], y[it[1]], y[it[3]]);
			ret = min(ret, f1 + f2 + 2 * max({ 0ll, a - d, c - b }));
		} while (next_permutation(it, it + n));
		cout << ret << endl;
	}
	return 0;
}
