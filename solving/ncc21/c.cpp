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

#ifdef DEBUG
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
	int n;
	cin >> n;
	int m = 3 * n;
	vector<int> a(m);
	F0R(i, m) cin >> a[i];
	multiset<int> left, right;
	int lmax = 0, rmin = 0;
	vector<int> suff(m + 2);
	vector<bool> okr(m + 2, false);
	for (int i = m - 1; i >= 0; i--) {
		right.insert(a[i]);
		rmin += a[i];
		if (sz(right) > n) {
			rmin -= *right.rbegin();
			right.erase(right.find(*right.rbegin()));
		}
		if (sz(right) >= n) {
			okr[i] = true;
		}
		suff[i] = rmin;
		// see(i, suff[i]);
	}
	int ans = -inf;
	F0R(i, m) {
		left.insert(a[i]);
		lmax += a[i];
		if (sz(left) > n) {
			lmax -= *left.begin();
			left.erase(left.find(*left.begin()));
		}
		if (sz(left) >= n && okr[i + 1]) {
			cmax(ans, lmax - suff[i + 1]);
		}
	}
	assert(ans != -inf);
	cout << ans << '\n';
}
