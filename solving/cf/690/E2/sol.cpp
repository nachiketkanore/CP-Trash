/*
Author: Nachiket Kanore
Created: Tuesday 15 December 2020 11:39:03 PM IST
(ツ) Bad times have a scientific value. These are occasions a good learner would not miss.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(mt_rng); }

template<int D, typename T> struct vec : public vector<vec<D - 1, T>> {
	static_assert(D >= 1, "Dimensions invalid");
	template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, const T& val = T()) : vector<T>(n, val) {} };

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 2e5 + 5, mod = 1e9+7;

int factmod[N];

void pre(){
    factmod[0] = 1;
    for(int i = 1; i < N; i++)
        factmod[i] = factmod[i - 1] * i % mod;
}

int power(int a, int b){
    int ret = 1;
    a %= mod;
    while(b > 0){
        if(b % 2)
            ret = ret * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ret;
}

int nCr(int n, int r){
    if(r > n)   return 0;
    int num = factmod[n];
    int deno = factmod[n - r] * factmod[r] % mod;
    deno = power(deno, mod - 2);
    int ans = num * deno % mod;
    return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	pre();
	int T;	cin >> T;
	while (T--) {
		int n;	cin >> n;
		int m, k;	cin >> m >> k;
		vector<int> a(n);	for (int &x : a) cin >> x;
		sort(ALL(a));
		int ans = 0;

		for (int i = 0; i < n; i++) {
			// largest j s.t a[j] <= a[i] + k
			int j = upper_bound(ALL(a), a[i] + k) - a.begin();
			j--;
			int len = j-i+1;
			// fixing the min element, then choosing the remaining ones
			ans += nCr(len-1, m-1);
			ans %= mod;
		}

		cout << ans << "\n";
	}
}
