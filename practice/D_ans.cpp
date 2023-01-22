#include <algorithm>
#include <iostream>

using namespace std;
int a[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		sort(a, a + n, greater<int>());
		long long sum = 0;
		for (int i = 0; i <= k; ++i)
			sum += a[i];

		cout << sum << '\n';
	}
	return 0;
}