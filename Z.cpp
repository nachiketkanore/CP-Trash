#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
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

#ifndef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

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

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	string s, a, b;
	cin >> s >> a >> b;

	vector<int> S(26), A(26), B(26);
	for (char ch : s)
		S[ch - 'a']++;
	for (char ch : a)
		A[ch - 'a']++;
	for (char ch : b)
		B[ch - 'a']++;

	int best = 0, best_a = 0, best_b = 0;

	for (int take_a = 0;; take_a++) {
		bool poss = true;
		F0R(ch, 26) poss &= A[ch] * take_a <= S[ch];
		if (poss) {
			vector<int> nS = S;
			F0R(ch, 26) nS[ch] -= A[ch] * take_a;
			int take_b = inf;
			F0R(ch, 26) if (B[ch]) cmin(take_b, nS[ch] / B[ch]);
			if (best < take_a + take_b) {
				best = take_a + take_b;
				best_a = take_a;
				best_b = take_b;
			}
		} else
			break;
	}

	F0R(i, 26) S[i] = 0;
	for (char ch : s)
		S[ch - 'a']++;
	while (best_a--) {
		cout << a;
		for (char ch : a)
			S[ch - 'a']--;
	}
	while (best_b--) {
		cout << b;
		for (char ch : b)
			S[ch - 'a']--;
	}
	F0R(ch, 26) while (S[ch]--) cout << (char)(ch + 'a');
	cout << '\n';
}
