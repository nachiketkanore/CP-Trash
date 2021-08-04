#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e13;

int n, a[N], b[N], ans[N];

int getSum(int L, int R) {
	assert(L <= R);
	return a[R] - a[L - 1];
}

void add(int L, int R, int val) {
	assert(L <= R);
	ans[L] += val;
	ans[R + 1] -= val;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		cin >> n;	
		FOR(i,1,n) {
			cin >> a[i];
			b[i] = a[i];
			a[i] += a[i - 1];
			ans[0] = ans[i] = 0;
		}

		FOR(i,1,n) {

			int right = i;
			int lo = i + 1, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				int sum = getSum(i + 1, mid) - getSum(mid, mid);
				if (b[i] >= sum) {
					right = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if (right != i) {
				// cerr << i << " , right = " << right << '\n';
				assert(right >= i + 1);
				add(i + 1, right, 1);
			}

			lo = 1, hi = i - 1;
			int left = i;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				int sum = getSum(mid, i - 1) - getSum(mid, mid);
				if (b[i] >= sum) {
					left = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			if (left != i) {
				// cerr << i << " , left = " << left << '\n';
				assert(left <= i - 1);
				add(left, i - 1, 1);
			}
		}		
		FOR(i,1,n) {
			ans[i] += ans[i - 1];
			cout << ans[i] << ' ';
		}	cout << '\n';
	}
}