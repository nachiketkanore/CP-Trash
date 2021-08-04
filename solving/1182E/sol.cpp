/*
Author: Nachiket Kanore
Created: Tuesday 29 December 2020 05:55:13 PM IST
(ツ) What is a weed? A plant whose virtues have not yet been discovered.
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

const int MOD = 1e9 + 6;
const int mod = 1e9 + 7;
 
long long power(long long a, long long n) {
    long long ans = 1;
    while (n) {
        if (n & 1)
        	ans = ans * a % mod;
        n >>= 1;
        a = a * a % mod;
    }
    return ans;
}
 
struct Matrix {
    int n;
    int a[5][5];
 
    Matrix(int n_) : n(n_) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            	a[i][j] = 0;
    }
 
};
 
Matrix operator*(Matrix A, Matrix B) {
    int n = A.n;
    Matrix res(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                res.a[i][j] += (int) A.a[i][k] * B.a[k][j] % MOD;
                res.a[i][j] %= MOD;
            }
    return res;
}
 
Matrix operator^(Matrix A, long long b) {
    int n = A.n;
    Matrix res(n), base = A;
    for (int i = 0; i < n; i++)res.a[i][i] = 1;
    while (b) {
        if (b & 1)res = res * base;
        base = base * base;
        b >>= 1;
    }
    return res;
}
 
Matrix a(3), b(5);

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	// tut : https://blog.csdn.net/qq_42671946/article/details/91488692
	
	long long n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    a.a[0][0] = 1;
    a.a[0][1] = 1;
    a.a[0][2] = 1;
    a.a[1][0] = 1;
    a.a[2][1] = 1;
    b.a[0][0] = 1;
    b.a[0][1] = 1;
    b.a[0][2] = 1;
    b.a[0][3] = 1;
    b.a[1][0] = 1;
    b.a[2][1] = 1;
    b.a[3][3] = 1;
    b.a[3][4] = 1;
    b.a[4][4] = 1;
    a = a ^ (n - 3);
    b = b ^ (n - 3);
    long long ans = 1;
    long long F1 = a.a[0][2] % MOD;
    long long F2 = a.a[0][1] % MOD;
    long long F3 = a.a[0][0] % MOD;
    see(F1, F2, F3);

    ans = power(f1, F1) * power(f2, F2) % mod * power(f3, F3) % mod;
    long long C = (b.a[0][3]*2 + b.a[0][4] * 2) % MOD;
    ans = ans * power(c, C) % mod;
    cout << ans;
 
}

// tut : https://blog.csdn.net/qq_42671946/article/details/91488692