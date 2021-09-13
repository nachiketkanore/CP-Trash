/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 04 September 2021 04:05:05 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <queue>
#include <set>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif


struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int INF = 1e18;

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 0, -1, 1};

vector<pair<double,double>> new_points(vector<double> X, vector<double> Y) {
	vector<pair<double,double>> add_pts;
	const int N = X.size();

	F0R (i,N) F0R (j,N) {
		if (i == j) continue;
		F0R (id1,8) {
			F0R (id2,8) {
				// line1
				int a1, b1, c1;
				int a2, b2, c2;
				{
					int x1 = X[i], y1 = Y[i];
					int x2 = x1 + dx[id1], y2 = y1 + dy[id1];
					a1 = y2 - y1;
					b1 = x1 - x2;
					c1 = y2 * (x2 - x1) - x2 * (y2 - y1);
				}
				{
					int x1 = X[j], y1 = Y[j];
					int x2 = x1 + dx[id2], y2 = y1 + dy[id2];
					a2 = y2 - y1;
					b2 = x1 - x2;
					c2 = y2 * (x2 - x1) - x2 * (y2 - y1);
				}
				double ax, ay;
				bool fx(false), fy(false);
				{
					int num = b1 * c2 - b2 * c1;
					int den = a1 * b2 - a2 * b1;
					if (den) {
						fx = true;
						ax = 1.* num / den;
					}
				}
				{
					int num = c1 * a2 - c2 * a1;
					int den = a1 * b2 - a2 * b1;
					if (den) {
						fy = true;
						ay = 1. * num / den;
					}
				}
				if (fx && fy) {
					add_pts.push_back(make_pair(ax, ay));
				}
			}
		}
	}

	return add_pts;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, ans = INF;
		cin >> N;
		vector<double> X(N), Y(N);
		F0R (i,N) cin >> X[i];
		F0R (i,N) cin >> Y[i];

		const double EPS = 1e-9;

		auto equal = [EPS](double one, double two) {
			return abs(one - two) < EPS;
		};

		auto get_weight = [&](double x1, double y1, double x2, double y2) {
			if (equal(x1, x2) && equal(y1, y2)) return 0;
			if (equal(x1, x2))
				return 1;
			if (equal(y1, y2))
				return 1;
			if (equal(x1 - y1, x2 - y2))
				return 1;
			if (equal(x1 + y1, x2 + y2))
				return 1;
			return 2;
		};

		F0R (s,N) {
			int get = 0;
			F0R (i,N) get += get_weight(X[s], Y[s], X[i], Y[i]);
			cmin(ans, get);
		}

		const vector<pair<double,double>> pts = new_points(X, Y);
		for (auto it: pts) {
			int get = 0;
			F0R (i,N) get += get_weight(it.first, it.second, X[i], Y[i]);
			cmin(ans, get);
		}
		cout << ans << '\n';
	}
}
