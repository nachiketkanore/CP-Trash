/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 05:41:09 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf = 1e18;

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

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S, T;
	for (int i = 0; i < 3; i++) {
		char ch;
		cin >> ch;
		S += ch;
	}
	for (int i = 0; i < 3; i++) {
		char ch;
		cin >> ch;
		T += ch;
	}
	if (S == T) {
		cout << "Yes\n";
		return 0;
	}
	map<string, int> perm;
	string curr = "RGB";
	sort(curr.begin(), curr.end());
	int id = 0;
	vector<string> all;
	do {
		perm[curr] = id++;
		all.push_back(curr);
	} while (next_permutation(curr.begin(), curr.end()));
	const int M = all.size();
	int dist[6][6];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = inf;
		}
	}
	for (string p : all) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < i; j++) {
				string pd = p;
				swap(pd[i], pd[j]);
				int u = perm[p], v = perm[pd];
				dist[u][v] = dist[v][u] = 1;
				// see(all[u], all[v]);
				// see(p, pd);
			}
		}
	}
	for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int from = perm[S], to = perm[T];
	if (dist[from][to] == 2) {
		cout << "Yes\n";
	} else if (dist[from][to] == 1) {
		cout << "No\n";
	} else {
		assert(0);
	}
	// for (int i = 0; i < 6; i++) {
	// 	for (int j = 0; j < 6; j++) {
	// 		if (dist[i][j] > 1e9) {
	// 			see(all[i], all[j]);
	// 		}
	// 		cout << dist[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	return 0;
}
