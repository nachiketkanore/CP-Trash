/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 01:19:31 PM IST
(ツ) Fear of failure is one attitude that will keep you at the same point in your life.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2000 + 5, inf = 1e9;

int n, k, mat[N][N], rowSum[N][N], colSum[N][N], ans;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	FOR(i, 1, n) {
		FOR(j, 1, n) {
			char ch;
			cin >> ch;
			mat[i][j] = (ch == 'W' ? 0 : 1);
			rowSum[i][j] = rowSum[i][j - 1] + mat[i][j];
			colSum[j][i] = colSum[j][i - 1] + mat[i][j];
		}
	}

	// Sliding window of (K x K) row-wise from left to right

	int leftCol = 1, rightCol = k;
	int leftGoodCols = 0, rightGoodCols = 0, insideGoodCols = 0;

	FOR(col, 1, k) {
		int windowSum = colSum[col][k] - colSum[col][0];
		int totalSum = colSum[col][n];
		if (windowSum == totalSum)
			++insideGoodCols;
	}

	FOR(col, k + 1, n) {
		if (colSum[col][n] == 0)
			rightGoodCols++;
	}

	while (rightCol <= n) {

		int insideGoodRows = 0, upGoodRows = 0, downGoodRows = 0;

		int fromRow = 1, toRow = k;

		FOR(i, fromRow, toRow) {
			int windowSum = rowSum[i][rightCol] - rowSum[i][leftCol - 1];
			int totalSum = rowSum[i][n];
			if (windowSum == totalSum)
				++insideGoodRows;
		}

		FOR(i, toRow + 1, n) {
			if (rowSum[i][n] == 0)
				++downGoodRows;
		}

		while (toRow <= n) {
			int get = upGoodRows + insideGoodRows + downGoodRows + leftGoodCols + insideGoodCols + rightGoodCols;
			ans = max(ans, get);

			int windowSum = rowSum[fromRow][rightCol] - rowSum[fromRow][leftCol - 1];
			int totalSum = rowSum[fromRow][n];
			if (windowSum == totalSum) {
				--insideGoodRows;
				upGoodRows++;
			}
			toRow++;
			fromRow++;
			windowSum = rowSum[toRow][rightCol] - rowSum[toRow][leftCol - 1];
			totalSum = rowSum[toRow][n];
			if (totalSum == windowSum) {
				insideGoodRows++;
				--downGoodRows;
			}
		}

		rightCol++;

		if (colSum[rightCol][n] == 0) {
			rightGoodCols--;
			insideGoodCols++;
		}
		if (colSum[leftCol][n] == 0) {
			--insideGoodCols;
			++leftGoodCols;
		}
		leftCol++;
	}

	cout << ans << "\n";
}
