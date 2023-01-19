/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 12 October 2021 12:58:24 PM IST
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

struct grid {
	int N;
	vector<string> mat;
	grid(int N) : N(N) {
		mat.resize(N);
		F0R(i, N) cin >> mat[i];
	}
	void rotate() {
		vector<string> new_mat;
		for (int j = N - 1; ~j; --j) {
			string row;
			F0R(i, N) row += mat[i][j];
			new_mat.push_back(row);
		}
		mat = new_mat;
	}
	bool check(grid other) const {
		assert(N == other.N);
		vector<pair<int, int>> pos_one, pos_two;
		F0R(i, N) F0R(j, N) {
			if (mat[i][j] == '#') {
				pos_one.push_back(make_pair(i, j));
			}
			if (other.mat[i][j] == '#') {
				pos_two.push_back(make_pair(i, j));
			}
		}
		if (sz(pos_one) ^ sz(pos_two))
			return false;
		sort(ALL(pos_one));
		sort(ALL(pos_two));
		vector<int> dx, dy;
		F0R(i, sz(pos_one)) {
			dx.push_back(pos_one[i].first - pos_two[i].first);
			dy.push_back(pos_one[i].second - pos_two[i].second);
			if (sz(dx) >= 2 && dx[sz(dx) - 1] != dx[sz(dx) - 2])
				return false;
			if (sz(dy) >= 2 && dy[sz(dy) - 1] != dy[sz(dy) - 2])
				return false;
		}
		return true;
	}
};

int32_t main() {
	int N;
	cin >> N;
	bool ans = false;
	grid one(N), two(N);
	F0R(_, 5) {
		one.rotate();
		F0R(_, 5) {
			ans |= one.check(two);
			if (ans)
				break;
			two.rotate();
		}
		if (ans)
			break;
	}
	cout << (ans ? "Yes" : "No");
}
