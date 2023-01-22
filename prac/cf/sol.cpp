#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void test() {
	return;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int n = 30; n <= 30; n++) {
		int ans = 0;
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b) {
				if (a * b <= 3 * __gcd(a, b) * __gcd(a, b)) {
					cout << a << ' ' << b << '\n';
					++ans;
				}
			}
		}
		cout << n << " : " << ans << '\n';
	}
	return 0;
}
