/*
Author: Nachiket Kanore
Created: Thursday 11 March 2021 09:36:19 PM IST
Reply Code Challenge 2021
*/
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, R) for (int i = (0); i < (R); i++)
#define REP(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

struct ans {
	int id, x, y;
	ans(int id, int x, int y) : id(id), x(x), y(y) {
	}
};

struct building {
	int x, y, L, C;
	building(int x, int y, int L, int C) : x(x), y(y), L(L), C(C) {
	}
	building() {
	}
};

struct antenna {
	int id, R, C;
	antenna(int id, int R, int C) : id(id), R(R), C(C) {
	}
	antenna() {
	}
};

int W, H, N, M, R;
int which_building[6000][6000];
int which_antenna[6000][6000];
vector<antenna> A;
vector<building> B;
vector<ans> answer;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inside(int i, int j) {
	return i >= 0 && i < H && j >= 0 && j < W;
}

void input() {
	cin >> W >> H;
	cin >> N >> M >> R;
	B.resize(N);
	A.resize(M);
	memset(which_building, -1, sizeof(which_building));
	FOR(i, N) {
		cin >> B[i].x >> B[i].y >> B[i].L >> B[i].C;
		which_building[B[i].x][B[i].y] = i;
	}
	FOR(i, M) {
		A[i].id = i;
		cin >> A[i].R >> A[i].C;
	}
}

int get_score(building b, antenna a) {
	return b.C * a.C - b.L * (0);
}

void solve() {
	sort(ALL(B), [&](building one, building two) { return make_pair(one.x, one.y) > make_pair(two.x, two.y); });
	sort(ALL(A), [&](antenna one, antenna two) {
		if (one.C == two.C)
			return one.R < two.R;
		return one.C < two.C;
	});

	for (building b : B) {
		if (!sz(A) || sz(answer) == M)
			break;
		int id = sz(A) - 1;
		answer.push_back(ans(A[id].id, b.x, b.y));
		A.pop_back();
	}

	while (sz(A)) {
		int best = -1, addx = -1, addy = -1;
		for (building b : B) {
			for (int k = 0; k < 4; k++) {
				int x = b.x + dx[k];
				int y = b.y + dy[k];
				if (inside(x, y) && which_building[x][y] < 0) {
					if (cmax(best, b.C * A.back().C)) {
						addx = x;
						addy = y;
					}
				}
			}
		}
		assert(~best);
		answer.push_back(ans(A.back().id, addx, addy));
		which_building[addx][addy] = 1;
		A.pop_back();
	}
}

void score() {
	assert(sz(answer) == M);
	// for (building b : B) {
	// 	REP(x,)
	// }
}

void output() {
	assert(sz(answer) >= 1 && sz(answer) <= M);
	cout << sz(answer) << '\n';
	for (ans X : answer)
		cout << X.id << ' ' << X.x << ' ' << X.y << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solve();
	output();
	score();
}
