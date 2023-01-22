#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int inf = 1e18;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline int rand(int l, int r) {
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void ARRAY(int n, int L, int R) {
	cout << n << '\n';
	FOR(i, 1, n) {
		cout << rand(L, R) << " \n"[i == n];
	}
}

void STRING(int n, char from, char to) {
	assert(from <= to);
	int L = from - 'a';
	int R = to - 'a';
	assert(L <= R);

	cout << n << '\n';
	FOR(i, 1, n) {
		char ch = (char)('a' + rand(L, R));
		cout << ch;
	}
	cout << '\n';
}

vector<pair<int, int>> TREE(int n) {
	// cout << n << '\n';

	vector<pair<int, int>> edges, ret;
	for (int i = 2; i <= n; ++i) {
		// edges.emplace_back(rand(1, i - 1), i);
		edges.emplace_back(i - 1, i);
	}

	vector<int> perm(n + 1); // re-naming vertices
	for (int i = 1; i <= n; ++i) {
		perm[i] = i;
	}
	shuffle(perm.begin() + 1, perm.end(), rng);

	shuffle(edges.begin(), edges.end(), rng); // random order of edges

	for (pair<int, int> edge : edges) {
		int a = edge.first, b = edge.second;
		if (rand() % 2) {
			swap(a, b); // random order of two vertices
		}
		// cout << perm[a] << ' ' << perm[b] << '\n';
		ret.emplace_back(perm[a], perm[b]);
	}
	return ret;
}

const int N = 1e6 + 5;

bool prime[N + 2];

vector<int> get_primes() {
	vector<int> ret;
	fill(prime + 2, prime + N, true);

	FOR(i, 2, 1000000) if (prime[i]) {
		if (rand(0, 1))
			ret.push_back(i);
		for (int j = 2 * i; j <= N; j += i)
			prime[j] = false;
	}
	FOR(t, 1, 10000) {
		ret.push_back(rand(1, 1000000));
	}
	shuffle(ret.begin(), ret.end(), rng);
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> val = get_primes();

	int n = rand(50000, 100000);
	cout << n << "\n";

	vector<pair<int, int>> edges = TREE(n);

	FOR(i, 1, n) {
		int id = rand(0, sz(val) - 1);
		cout << val[id] << " \n"[i == n];
	}

	int Q = n << 2;
	cout << Q << "\n";

	std::vector<int> done;

	while (Q--) {
		int type = rand(1, 10);
		if (type > 7 && sz(edges)) {
			// these u, v should be valid
			int u = edges.back().first, v = edges.back().second;
			done.push_back(u);
			done.push_back(v);
			edges.pop_back();
			cout << "A " << u << " " << v << "\n";
		} else {
			int u, v;
			if (sz(done)) {
				int id1 = rand(0, sz(done) - 1), id2 = rand(0, sz(done) - 1);
				u = done[id1], v = done[id2];
			} else {
				u = rand(1, n), v = rand(1, n);
			}
			cout << "B " << u << " " << v << "\n";
		}
	}
}