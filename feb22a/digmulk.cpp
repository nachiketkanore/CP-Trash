/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 February 2022 09:07:56 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

// code snippet taken from code-library
const int mod = 1e9 + 7;
struct Mat {
	int n, m;
	vector<vector<int>> a;
	Mat() {
	}
	Mat(int _n, int _m) {
		n = _n;
		m = _m;
		a.assign(n, vector<int>(m, 0));
	}
	Mat(vector<vector<int>> v) {
		n = v.size();
		m = n ? v[0].size() : 0;
		a = v;
	}
	inline void make_unit() {
		assert(n == m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				a[i][j] = i == j;
		}
	}
	inline Mat operator+(const Mat& b) {
		assert(n == b.n && m == b.m);
		Mat ans = Mat(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
			}
		}
		return ans;
	}
	inline Mat operator-(const Mat& b) {
		assert(n == b.n && m == b.m);
		Mat ans = Mat(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
			}
		}
		return ans;
	}
	inline Mat operator*(const Mat& b) {
		assert(m == b.n);
		Mat ans = Mat(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
				}
			}
		}
		return ans;
	}
	inline Mat pow(long long k) {
		assert(n == m);
		Mat ans(n, n), t = a;
		ans.make_unit();
		while (k) {
			if (k & 1)
				ans = ans * t;
			t = t * t;
			k >>= 1;
		}
		return ans;
	}
	inline Mat& operator+=(const Mat& b) {
		return *this = (*this) + b;
	}
	inline Mat& operator-=(const Mat& b) {
		return *this = (*this) - b;
	}
	inline Mat& operator*=(const Mat& b) {
		return *this = (*this) * b;
	}
	inline bool operator==(const Mat& b) {
		return a == b.a;
	}
	inline bool operator!=(const Mat& b) {
		return a != b.a;
	}
};

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K, M;
		cin >> N >> K >> M;
		int base_case[10], memo[10][10];
		memset(base_case, 0, sizeof(base_case));
		memset(memo, 0, sizeof(memo));
		string S;
		cin >> S;
		for (char ch : S) {
			base_case[ch - '0']++;
		}
		for (int i = 0; i < 10; i++) {
			string prod = to_string(i * K);
			for (char d : prod) {
				memo[i][d - '0']++;
			}
		}
		Mat dp(10, 10);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				dp.a[i][j] = memo[j][i];
			}
		}
		Mat base(10, 1);
		for (int i = 0; i < 10; i++) {
			base.a[i][0] = base_case[i];
		}
		// M steps
		dp = dp.pow(M) * base;
		int ans = 0;
		for (int i = 0; i < 10; i++) {
			ans = (ans + dp.a[i][0]) % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}
