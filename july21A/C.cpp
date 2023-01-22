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
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int A[N + 5];

int32_t main() {
	FOR(i, 1, N) {
		string val = to_string(i);
		string left;
		F0R(j, sz(val) - 1) left += val[j];
		string right = left;
		reverse(ALL(right));
		string mid;
		mid += val.back();
		string get = left + mid + right;
		A[i] = stoll(get);
	}

	FOR(i, 2, N) A[i] += A[i - 1];

	auto power = [&](int a, int b) {
		int ret = 1;
		while (b) {
			if (b & 1)
				ret = ret * a % MOD;
			a = a * a % MOD;
			b >>= 1;
		}
		return ret;
	};

	int Q;
	cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		int sum = A[R] - A[L];
		int val = A[L] - A[L - 1];
		int ans = power(val, sum);
		cout << ans << '\n';
	}
}
