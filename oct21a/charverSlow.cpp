/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 06 October 2021 03:12:04 PM IST
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

const int MOD = 998244353;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int M;
		cin >> M;
		int C[M];
		F0R(i, M) cin >> C[i];
		int N;
		cin >> N;
		int A[N][N], Apow[N][N];
		F0R(i, N) F0R(j, N) {
			cin >> A[i][j];
			Apow[i][j] = A[i][j];
		}
		int B[N][N];
		F0R(i, N) F0R(j, N) if (i == j) B[i][j] = C[0];
		else B[i][j] = 0;
		for (int k = 1; k < M; k++) {
			F0R(i, N) F0R(j, N) {
				B[i][j] += C[k] * Apow[i][j];
				if (B[i][j] >= MOD)
					B[i][j] %= MOD;
			}
			int res[N][N];
			F0R(i, N) F0R(j, N) res[i][j] = 0;
			F0R(i, N) F0R(j, N) F0R(l, N) {
				res[i][j] += Apow[i][l] * A[l][j];
				if (res[i][j] >= MOD)
					res[i][j] %= MOD;
			}
			F0R(i, N) F0R(j, N) Apow[i][j] = res[i][j];
		}
		bool ok = true;
		F0R(i, N) F0R(j, N) ok &= B[i][j] == 0;
		cout << (ok ? "YES\n" : "NO\n");
	}
}
