/*
Author: Nachiket Kanore
Created: Tuesday 29 December 2020 07:56:51 PM IST
(ツ) Real magic in relationships means an absence of judgement of others.
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
 
const int N = 2e5 + 5, inf = 1e18;

namespace fft{
	using cd = complex<double>;
	const double PI = acos(-1);

	void fft(vector<cd> & a, bool invert) {
	    int n = a.size();
	    if (n == 1)
	        return;

	    vector<cd> a0(n / 2), a1(n / 2);
	    for (int i = 0; 2 * i < n; i++) {
	        a0[i] = a[2*i];
	        a1[i] = a[2*i+1];
	    }
	    fft(a0, invert);
	    fft(a1, invert);

	    double ang = 2 * PI / n * (invert ? -1 : 1);
	    cd w(1), wn(cos(ang), sin(ang));
	    for (int i = 0; 2 * i < n; i++) {
	        a[i] = a0[i] + w * a1[i];
	        a[i + n/2] = a0[i] - w * a1[i];
	        if (invert) {
	            a[i] /= 2;
	            a[i + n/2] /= 2;
	        }
	        w *= wn;
	    }
	}

	vector<int> multiply(vector<int> const& a, vector<int> const& b) {
	    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	    int n = 1;
	    while (n < a.size() + b.size()) 
	        n <<= 1;
	    fa.resize(n);
	    fb.resize(n);

	    fft(fa, false);
	    fft(fb, false);
	    for (int i = 0; i < n; i++)
	        fa[i] *= fb[i];
	    fft(fa, true);

	    vector<int> result(n);
	    for (int i = 0; i < n; i++)
	        result[i] = round(fa[i].real());
	    return result;
	}

}


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		int n;	cin >> n;
		vector<int> a(n+1), b(n+1);
		for (int i = n; ~i; --i) cin >> a[i];
		for (int i = n; ~i; --i) cin >> b[i];

		vector<int> answer = fft::multiply(a, b);
		answer.pop_back();
		answer.pop_back();
		answer.pop_back();
		// assert(sz(answer) == 2*n+1);
		reverse(ALL(answer));
		for (int &x : answer) cout << x << " ";
			cout << "\n";
	}
}
