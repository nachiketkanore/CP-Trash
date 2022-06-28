// For heavy recursions
// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define test  \
	int t;    \
	cin >> t; \
	while (t--)
#define fast                       \
	ios_base ::sync_with_stdio(0); \
	cin.tie(NULL);                 \
	cout.tie(NULL)
using namespace std;

void __print(int x) {
	cerr << x;
}
void __print(float x) {
	cerr << x;
}
void __print(double x) {
	cerr << x;
}
void __print(long double x) {
	cerr << x;
}
void __print(char x) {
	cerr << '\'' << x << '\'';
}
void __print(const char* x) {
	cerr << '\"' << x << '\"';
}
void __print(const string& x) {
	cerr << '\"' << x << '\"';
}
void __print(bool x) {
	cerr << (x ? "true" : "false");
}

template <typename T, typename V> void __print(const pair<T, V>& x) {
	cerr << '{';
	__print(x.first);
	cerr << ',';
	__print(x.second);
	cerr << '}';
}
template <typename T> void __print(const T& x) {
	int f = 0;
	cerr << '{';
	for (auto& i : x)
		cerr << (f++ ? "," : ""), __print(i);
	cerr << "}";
}
void _print() {
	cerr << "]\n";
}
template <typename T, typename... V> void _print(T t, V... v) {
	__print(t);
	if (sizeof...(v))
		cerr << ", ";
	_print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...)                 \
	cerr << "[" << #x << "] = ["; \
	_print(x)
#else
#define see(x...)
#endif

void solve() {
	int n;
	cin >> n;
	vector<set<int>> mp(n + 1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; j++)
				if (j <= 50)
					mp[i + 1].insert(j);
		}
	}
	int m;
	cin >> m;
	vector<vector<pair<int, set<int>>>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int x;
		cin >> x;
		set<int> v;
		while (x--) {
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; j++)
				if (j <= 50)
					v.insert(j);
		}
		graph[a].push_back({ b, v }), graph[b].push_back({ a, v });
	}
	queue<pair<int, int>> q;
	int x, d;
	cin >> x >> d;
	vector<vector<int>> vis(n + 1, vector<int>(100, 0));
	bool s[100] = { false };
	for (int i : mp[x])
		q.push({ x, i });
	// q.push({x,0});
	while (!q.empty()) {
		pair<int, int> p = q.front();
		// cout<<p.first<<" "<<p.second<<"\n";
		q.pop();
		if (p.first == d) {
			// s.insert(p.second);
			s[p.second] = true;
		}
		vis[p.first][p.second] = 1;
		for (auto i : graph[p.first]) {
			int w = i.first;
			// cout<<w<<", ";
			if (i.second.count(p.second) && mp[w].count(p.second) && !vis[w][p.second]) {
				vis[w][p.second] = 1, q.push({ w, p.second });
				// cout<<w<<" "<<p.second<<"\n";
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		ans += s[i];
	}
	cout << ans << '\n';
	// cout << s.size() << '\n';
}

signed main() {
	fast;
	test {
		solve();
	}
	return 0;
}
