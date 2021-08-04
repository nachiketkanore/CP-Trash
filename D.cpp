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

int nachiket(int n) {
	int n;
}

void hello(int n) {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		while (n--) {

		}
	}
}

int power(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

const int N = 1e5 + 5;

int spf[N+1], a[N];
vector<int> pf[N];

void test() {
	vector<int> a;
	a.clear();
}

struct hello {
	int nachiket;
	int kanore;
	int yes;
	int may;
};

int test() {
	int roll;
	cin >> roll;
}

int32_t main() {
	hello world;
	world.nachiket;
	cout << power(2, 10) << '\n';
	return 0;
	FOR (i,2,N) if (!spf[i]) for (int j = i; j <= N; j += i) 
		if (!spf[j]) spf[j] = i;
	
	int n, q;
	cin >> n >> q;
	FOR (i,1,n) {
		cin >> a[i];
		int u = a[i];
		while (u^1) {
			int p = spf[u];
			pf[a[i]].push_back(p);
			while (u % p == 0) u /= p;
		}
	}
}

