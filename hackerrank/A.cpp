#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 5e5 + 5;

int n, arr[N];

// can be used for Range min/max/gcd range query in O(1)
class sparseTable {
	public:
	int RMQ[20][N];
	int floorlog[N];

	void precompute(int n) {
		for (int i = 0; (1 << i) < N; i++) {
			for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
				floorlog[j] = i;
		}

		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = arr[i];			   // leaf value
			int mxj = floorlog[n - i + 1]; // 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMQ[j][i] = max(RMQ[j - 1][i], RMQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int query(int L, int R) {
		int k = floorlog[R - L + 1];					 // 2^k <= R-L+1
		return max(RMQ[k][L], RMQ[k][R - (1 << k) + 1]); // operation
	}
} T;

int32_t main() {
	int q;
	cin >> n >> q;
	FOR(i, 1, n) cin >> arr[i];

	T.precompute(n);

	while (q--) {
		int k;
		cin >> k;
		int ans = inf;
		FOR(i, 1, n) {
			int j = i + k - 1;
			if (j > n)
				break;
			cmin(ans, T.query(i, j));
		}
		cout << ans << '\n';
	}
}
