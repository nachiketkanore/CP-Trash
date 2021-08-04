/**
 *	Author: Nachiket Kanore
 *	Created: Monday 14 June 2021 06:24:53 PM IST
**/
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 


const int MOD = 1e9 + 7;
struct mi {
	using ll = long long;
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
	mi& operator+=(const mi& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
	mi& operator-=(const mi& m) { if ((v -= m.v) < 0) v += MOD;	return *this; }
	mi& operator*=(const mi& m) { v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
			return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); return pow(a,MOD-2);	}

	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	mi operator++(int32_t) { mi temp; temp.v = v++; return temp; }
	mi operator--(int32_t) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v; return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x; is >> x;
		m.v = x;
		return is;
	}
};

const int N = 2e5 + 5;
int spf[N+1];
multiset<int> all[N+1];

vector<pair<int,int>> get_pf(int u) {
	vector<pair<int,int>> ret;
	while (u > 1) {
		int p = spf[u];
		int cnt = 0;
		while (u % p == 0) ++cnt, u /= p;
		ret.push_back(make_pair(p, cnt));
	}
	return ret;
}

int32_t main() {
	FOR (i,2,N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
	int n, q;
	cin >> n >> q;
	vector<map<int,int>> solo(n+1);
	FOR (i,1,n) {
		int u;
		cin >> u;
		vector<pair<int,int>> pf = get_pf(u);
		for (auto [p, e]: pf) {
			all[p].insert(e);
			solo[i][p] = e;
		}
	}
	mi ans = 1;
	FOR (i,2,N) {
		if (sz(all[i]) == n)
			ans *= pow(mi(i), *all[i].begin());
	}
	while (q--) {
		int id, val;
		cin >> id >> val;
		vector<pair<int,int>> pf = get_pf(val);
		for (auto [p, e]: pf) {
			if (sz(all[p]) == n)
				ans /= pow(mi(p), *all[p].begin());
			if (solo[id].count(p)) {
				int old = solo[id][p];
				all[p].erase(all[p].find(old));
				solo[id][p] += e;
				all[p].insert(old + e);
			} else {
				solo[id][p] = e;
				all[p].insert(e);
			}
			if (sz(all[p]) == n)
				ans *= pow(mi(p), *all[p].begin());
		}
		cout << ans << '\n';
	}
}
