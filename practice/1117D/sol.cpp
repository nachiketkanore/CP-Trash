/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 08 October 2022 12:39:09 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MOD = 1e9 + 7;
int add(int a, int b) {
	int res = a + b;
	if (res >= MOD)
		return res - MOD;
	return res;
}

int mult(int a, int b) {
	long long res = a;
	res *= b;
	if (res >= MOD)
		return res % MOD;
	return res;
}

const int SZ = 105;
struct matrix {
	int arr[SZ][SZ];

	matrix() {
		reset();
	}

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
int N, M;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	if (M > N) {
		cout << "1\n";
		return 0;
	}

	matrix I;
	I.arr[0][0] = I.arr[0][M - 1] = 1;
	for (int i = 1; i < M; i++) {
		I.arr[i][i - 1] = 1;
	}

	I = power(I, N - M + 1);

	int ans = 0;
	F0R(i, M) ans = add(ans, I.arr[0][i]);
	cout << ans << '\n';

	return 0;
}
