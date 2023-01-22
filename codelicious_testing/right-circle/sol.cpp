/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 April 2022 05:37:40 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

void findCircle(int x1, int y1, int x2, int y2, int x3, int y3) {
	int x12 = x1 - x2;
	int x13 = x1 - x3;

	int y12 = y1 - y2;
	int y13 = y1 - y3;

	int y31 = y3 - y1;
	int y21 = y2 - y1;

	int x31 = x3 - x1;
	int x21 = x2 - x1;

	// x1^2 - x3^2
	int sx13 = pow(x1, 2) - pow(x3, 2);

	// y1^2 - y3^2
	int sy13 = pow(y1, 2) - pow(y3, 2);

	int sx21 = pow(x2, 2) - pow(x1, 2);
	int sy21 = pow(y2, 2) - pow(y1, 2);

	int f = ((sx13) * (x12) + (sy13) * (x12) + (sx21) * (x13) + (sy21) * (x13)) / (2 * ((y31) * (x12) - (y21) * (x13)));
	int g = ((sx13) * (y12) + (sy13) * (y12) + (sx21) * (y13) + (sy21) * (y13)) / (2 * ((x31) * (y12) - (x21) * (y13)));

	int c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1;

	// eqn of circle be x^2 + y^2 + 2*g*x + 2*f*y + c = 0
	// where centre is (h = -g, k = -f) and radius r
	// as r^2 = h^2 + k^2 - c
	int h = -g;
	int k = -f;
	int sqr_of_r = h * h + k * k - c;

	// r is the radius
	float r = sqrt(sqr_of_r);

	cout << h << ' ' << k << ' ' << r << '\n';
}

void solve() {
	int N;
	cin >> N;
	assert(3 <= N && N <= 100);
	vector<pair<int, int>> A(N);
	F0R(i, N) {
		cin >> A[i].first >> A[i].second;
	}
	findCircle(A[0].first, A[0].second, A[1].first, A[1].second, A[2].first, A[2].second);
	// assert(false);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	// assert(1 <= T && T <= 1000);
	while (T--) {
		solve();
	}
	return 0;
}
