/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 10:14:21 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;
const int MOD = 1e9 + 7;
const int SZ  = 105;

int add(int a, int b) {
	int res = a + b;
	if (res >= MOD)
		return res % MOD;
	return res;
}

int mult(int a, int b) {
	long long res = a;
	res *= b;
	if (res >= MOD)
		return res % MOD;
	return res;
}

struct matrix {
	int arr[SZ][SZ];

	void reset() {
		memset(arr, 0, sizeof(arr));
	}

	void makeiden() {
		reset();
		for (int i = 0; i < SZ; i++) {
			arr[i][i] = 1;
		}
	}

	matrix operator+(const matrix& o) const {
		matrix res;
		for (int i = 0; i < SZ; i++) {
			for (int j = 0; j < SZ; j++) {
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator*(const matrix& o) const {
		matrix res;
		for (int i = 0; i < SZ; i++) {
			for (int j = 0; j < SZ; j++) {
				res.arr[i][j] = 0;
				for (int k = 0; k < SZ; k++) {
					res.arr[i][j] = add(res.arr[i][j], mult(arr[i][k], o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

matrix power(matrix a, int b) {
	matrix res;
	res.makeiden();
	while (b) {
		if (b & 1) {
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
int N, M, K, H;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K >> H;
	if (K == 0) {
		cout << "0\n";
		return 0;
	}
	matrix A;
	A.reset();
	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		A.arr[u][v] = 1;
		A.arr[v][u] = 1;
	}
	A		= power(A, K);
	int ans = A.arr[H][H] % MOD;
	cout << ans;
	return 0;
}
