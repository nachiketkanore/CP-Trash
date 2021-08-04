/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 05:46:43 PM IST
(ツ) Adversity has the effect of eliciting talents, which in prosperous circumstances would have lain dormant.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int gcdExtended(int a, int b, int* x, int* y) {  
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1); 

    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

// (1/a) % m when (a and m are coprime)
int modInverse(int a, int m) { 
	assert(__gcd(a, m) == 1);
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        assert(false);
    else { 
        int res = (x % m + m) % m; 
        return res;
    } 
} 

int power(int a, int b, int mod) {
	int ret = 1;
	a %= mod;
	while (b) {
		if (b&1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int A, B, C, M;
	cin >> A >> B >> C >> M;
	cout << (power(A, B, M) * modInverse(C, M)) % M << "\n";
}
