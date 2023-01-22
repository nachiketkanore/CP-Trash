/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 12 October 2021 03:58:29 PM IST
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

class box {
	public:
	int w, h;
	bool operator<(const box& other) const {
		if (w == other.w)
			return h > other.h;
		return w < other.w;
	}
	friend istream& operator>>(istream& io, box& B) {
		io >> B.w >> B.h;
		return io;
	}
	bool check(const box& other) const {
		return w < other.w && h < other.h;
	}
};

struct BIT {
	int N;
	vector<int> bit;

	void init(int n) {
		N = n;
		bit.assign(n + 1, 0);
	}

	void updateMax(int idx, int val) {
		while (idx <= N) {
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int prefMax(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
} dp;

int32_t main() {
	dp.init(100005);
	int N, ans = 0;
	cin >> N;
	vector<box> A(N);
	F0R(i, N) {
		cin >> A[i];
	}
	sort(ALL(A));
	F0R(i, sz(A)) {
		int best = dp.prefMax(A[i].h - 1) + 1;
		cmax(best, int(1));
		cmax(ans, best);
		dp.updateMax(A[i].h, best);
	}
	cout << ans << '\n';
}
