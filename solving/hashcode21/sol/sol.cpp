/* HashCode 2021 - Nachiket Kanore (Team: Pretests Passed) */

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
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
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

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r) {
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

struct edge {
	int to, w;
	string name;
	edge(int to_, int w_, string name_) {
		to = to_;
		w = w_;
		name = name_;
	}
};

const int N = 1e5 + 5;
int tot_time, n, e, cars, bonus;
vector<edge> to[N], from[N];
map<string, int> cnt_edge;
map<string, pair<int, int>> connection;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tot_time >> n >> e >> cars >> bonus;
	for (int i = 0; i < e; i++) {
		int u, v, req;
		cin >> u >> v;
		string name;
		cin >> name >> req;
		to[u].push_back(edge(v, req, name));
		connection[name] = { u, v };
		from[v].push_back(edge(u, req, name)); // reverse edge just for finding incoming edges
	}

	set<int> take;

	for (int i = 0; i < cars; i++) {
		int path_len;
		cin >> path_len;
		string name;
		while (path_len--) {
			cin >> name;
			cnt_edge[name]++;
			if (connection.count(name)) {
				pair<int, int> uv = connection[name];
				take.insert(uv.second);
			}
		}
	}

	vector<int> perm(ALL(take));

	cout << sz(perm) << '\n';
	for (int i : perm) {
		vector<edge>& incoming = from[i];
		cout << i << '\n';
		sort(ALL(incoming), [&](edge one, edge two) { return one.w < two.w; });

		while (sz(incoming) > 10)
			incoming.pop_back();

		cout << sz(incoming) << '\n';
		for (edge E : incoming) {
			int green = rand(1, 2);
			cout << E.name << ' ' << green << '\n';
		}
	}
}

/*
3
1
2
rue-d-athenes 2
rue-d-amsterdam 1
0
1
rue-de-londres 2
2
1
rue-de-moscou 1
*/