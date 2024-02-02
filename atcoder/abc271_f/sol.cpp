/**
 *    Author: Nachiket Kanore
 *    Created: Friday 02 February 2024 10:53:57 AM IST
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

const int MAX = 22;
int N, mat[MAX][MAX];
vector<int> first_half[MAX][MAX];
vector<int> second_half[MAX][MAX];
vector<int> add;

void dfs1(int i, int j, int xorval) {
	if (i == 1 && j == 1) {
		add.push_back(xorval);
		return;
	}
	if (i - 1 >= 1)
		dfs1(i - 1, j, xorval ^ mat[i - 1][j]);
	if (j - 1 >= 1)
		dfs1(i, j - 1, xorval ^ mat[i][j - 1]);
}
void dfs2(int i, int j, int xorval) {
	if (i == N && j == N) {
		add.push_back(xorval);
		return;
	}
	if (i + 1 <= N)
		dfs2(i + 1, j, xorval ^ mat[i + 1][j]);
	if (j + 1 <= N)
		dfs2(i, j + 1, xorval ^ mat[i][j + 1]);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	FOR(i, 1, N) FOR(j, 1, N) cin >> mat[i][j];

	FOR(i, 1, N) FOR(j, 1, N) {
		if (i + j == N) {
			add.clear();
			dfs1(i, j, mat[i][j]);
			first_half[i][j] = add;
		}
		if (i + j == N + 2) {
			add.clear();
			dfs2(i, j, mat[i][j]);
			second_half[i][j] = add;
		}
	}
	int answer = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i + j == N + 1) {
				vector<int> up; //, down;
				// [i-1,j] [i,j-1]
				for (int x : first_half[i - 1][j])
					up.push_back(x);
				for (int x : first_half[i][j - 1])
					up.push_back(x);
				// [i+1,j] [i,j+1]
				/*
				for (int x : second_half[i + 1][j])
					down.push_back(x);
				for (int x : second_half[i][j + 1])
					down.push_back(x);
				*/
				map<int, int> down;
				for (int x : second_half[i + 1][j])
					down[x]++;
				for (int x : second_half[i][j + 1])
					down[x]++;

				for (int x : up) {
					answer += down[(x ^ mat[i][j])];
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}
