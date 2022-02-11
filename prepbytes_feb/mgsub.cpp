/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 February 2022 12:11:23 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int f(int u) {
    int r = sqrt(u);
    if (r * r == u)
		return 1;
	return 0;
}


int solve(int ar[], int n) {
    int temp[2] = { 1, 0 };
    int result = 0, val = 0;
    for (int i = 0; i <= n - 1; i++) {
        val = ((val + ar[i]) % 2 + 2) % 2;
        temp[val]++;
    }

    result = (temp[0] * temp[1]);

    return (result);
}

int32_t main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = f(a[i]);
	}
	cout << solve(a, n);
	return 0;
}
