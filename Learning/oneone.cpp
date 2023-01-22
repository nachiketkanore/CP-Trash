/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 12:24:13 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
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

int MOD;

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

const int SZ = 2;
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

int get_brute(int N, int MOD) {
	int ret = 0;
	FOR(i, 1, N) {
		ret = (ret * 10 + 1) % MOD;
	}
	return ret;
}

int32_t main() {
	srand(time(0));
	int T = 100000;
	int id = 0;
	/* cin >> T; */
	while (id++ ^ T) {
		int N;
		N = rand() % 1000 + 1;
		MOD = rand() % 1000 + 5;
		/* cin >> N >> MOD; */
		matrix A;
		A.arr[0][0] = 10;
		A.arr[0][1] = 0;
		A.arr[1][0] = 10;
		A.arr[1][1] = 1;
		A = power(A, N - 1);
		int second = A.arr[1][0] + A.arr[1][1];
		second %= MOD;
		int brute = get_brute(N, MOD);
		assert(brute == second);
		/* cout << second << '\n'; */
		cout << "TEST " << id << " : OK" << '\n';
	}
}
