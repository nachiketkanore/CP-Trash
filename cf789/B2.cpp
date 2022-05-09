/**
 *    Author: Solve Machine
 *    Created: Sunday 08 May 2022 08:03:40 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int INF = 1e15;
int N, dp[2][2][200002];
string S, T;

int go(int id, int prev_cnt, int prev_val) {
	if (id == N) {
		if (prev_cnt % 2 == 0)
			return 0;
		return INF;
	}
	int& ans = dp[prev_cnt % 2][prev_val][id];
	if (~ans)
		return ans;
	ans = INF;

	// keep same
	{
		int put = S[id] - '0';
		int c1 = INF, c2 = INF;
		if (prev_val == put) {
			c1 = min(c1, go(id + 1, prev_cnt + 1, put));
			if (prev_cnt % 2 == 0) {
				c1 = min(c1, go(id + 1, 1, put));
			}
		} else {
			if (prev_cnt % 2 == 0) {
				c2 = min(c2, go(id + 1, 1, put));
			}
		}
		ans = min({ ans, c1, c2 });
	}

	// change
	{
		int put = (S[id] - '0') ^ 1;
		int c1 = INF, c2 = INF;
		if (prev_val == put) {
			c1 = min(c1, 1 + go(id + 1, prev_cnt + 1, put));
			if (prev_cnt % 2 == 0) {
				c1 = min(c1, 1 + go(id + 1, 1, put));
			}
		} else {
			if (prev_cnt % 2 == 0) {
				c2 = min(c2, 1 + go(id + 1, 1, put));
			}
		}
		ans = min({ ans, c1, c2 });
	}

	return ans;
}

void add(const int x) {
	T += (char)(x + '0');
}

void trace(int id, int prev_cnt, int prev_val) {
	if (id == N) {
		if (prev_cnt % 2 == 0)
			return;
		assert(false);
		return;
	}
	int ans = go(id, prev_cnt, prev_val);

	// keep same
	{
		int put = S[id] - '0';
		int c1 = INF, c2 = INF;
		if (prev_val == put) {
			c1 = min(c1, go(id + 1, prev_cnt + 1, put));
			if (c1 == ans) {
				add(put);
				return trace(id + 1, prev_cnt + 1, put);
			}
			if (prev_cnt % 2 == 0) {
				c1 = min(c1, go(id + 1, 1, put));
				if (c1 == ans) {
					add(put);
					return trace(id + 1, 1, put);
				}
			}
		} else {
			if (prev_cnt % 2 == 0) {
				c2 = min(c2, go(id + 1, 1, put));
				if (c2 == ans) {
					add(put);
					return trace(id + 1, 1, put);
				}
			}
		}
	}

	// change
	{
		int put = (S[id] - '0') ^ 1;
		int c1 = INF, c2 = INF;
		if (prev_val == put) {
			c1 = min(c1, 1 + go(id + 1, prev_cnt + 1, put));
			if (c1 == ans) {
				add(put);
				return trace(id + 1, prev_cnt + 1, put);
			}
			if (prev_cnt % 2 == 0) {
				c1 = min(c1, 1 + go(id + 1, 1, put));
				if (c1 == ans) {
					add(put);
					return trace(id + 1, 1, put);
				}
			}
		} else {
			if (prev_cnt % 2 == 0) {
				c2 = min(c2, 1 + go(id + 1, 1, put));
				if (c2 == ans) {
					add(put);
					return trace(id + 1, 1, put);
				}
			}
		}
	}

	assert(false);
}

int count_groups(const string& T) {
	const int M = T.size();
	int ans = 0;
	for (int i = 0; i < N;) {
		int j = i, cnt = 0;
		while (j < N && T[j] == T[i]) {
			j++;
			cnt++;
		}
		++ans;
		// assert(cnt % 2 == 0);
		i = j;
	}
	return ans;
}

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cout << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cout << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

#include <chrono>
#include <random>

inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve() {
	S.clear();
	N = 2 * rand(1, 20);
	FOR(i, 1, N) {
		S += (char)('0' + rand(0, 1));
	}
	cout << N << ' ' << S << '\n';
	// cin >> N >> S;
	F0R(i, 2) F0R(j, 2) F0R(k, N) dp[i][j][k] = -1;
	int c1 = go(0, 0, 1), c2 = go(0, 0, 0);
	int ans = min(c1, c2);
	// see("HERE");
	T.clear();
	if (c1 == ans) {
		trace(0, 0, 1);
	} else {
		trace(0, 0, 0);
	}
	assert(ans <= N);
	see(count_groups(S), count_groups(T));
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 10;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
