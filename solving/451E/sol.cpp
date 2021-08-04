/*
Author: Nachiket Kanore
Created: Saturday 26 December 2020 06:13:56 PM IST
(ツ) The creative adult is the child who survived.
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

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int mod = 1e9+7;

const int N = 25;
int n, s, f[20], ifact[N+1];

int power(int a, int b, int mod){
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

int inv_mod(int x) { return power(x, mod-2, mod); }

int get_NCR(int N, int R) {
	if (N < 0 || R > N) return 0;
	int ans = 1;
	// NCR = n * (n-1) * (n-2) * ... * (n-r+1) / fact(r)
	// numerator and denominator have upto 20 terms, ;) DOABLE

	for (int i = N; i >= (N-R+1); i--) {
		int mul = i % mod;
		ans = (ans * mul) % mod;
	}
	ans = (ans * ifact[R]) % mod;

	return ans;
}

void pre() {
	int fact = 1;
	ifact[0] = inv_mod(fact);
	for (int i = 1; i <= N; i++) {
		fact *= i;
		fact %= mod;
		ifact[i] = inv_mod(fact);
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	pre();
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	int ans = 0;

	for (int mask = 0; mask < (1 << n); mask++) {
		int sign = 1;
		int taken = 0;
		for (int i = 0; i < n; i++) 
			if (mask >> i & 1) {
				sign *= -1;
				taken += f[i] + 1;
			}
		int remain = s - taken;
		// find coeff of remain in (1 - x) ^ (-n)
		// coeff of k in (1 - x) ^ (-n) = (n + k - 1, k) <= nCr
		// 								= (n + k - 1, n - 1) <= using nCr(a, b) = nCr(a, a - b)
		// hence coeff of remain in (1 - x) ^ (-n) = (n + remain - 1, n - 1)
		
		int coeff = get_NCR(n + remain - 1, n - 1);
		if (sign > 0) 
			ans = (ans + coeff) % mod;
		else 
			ans = (ans - coeff + mod) % mod;
	}

	cout << ans << "\n";
}
