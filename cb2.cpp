/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 December 2021 03:11:58 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

string original;
int N;

bool check(const string& S) {
    assert(sz(S) == N);
    if (S[0] == '0' && sz(S) != 1) return false;
    char X = 'a';
    int val_mod = 0;
    F0R (i,N) {
        if (original[i] == 'X') {
            if (X == 'a') X = S[i];
            else {
                if (X != S[i]) return false;
            }
        }
        val_mod = (val_mod * 10 + (S[i]-'0')) % 25;
    }
    return val_mod == 0;
}

int go(string S, int id = 1) {
    // pruning with simple cases
    if (sz(S) == N) { return check(S); }

    int ans = 0;

    if (original[id] == '_' || original[id] == 'X') {
        F0R (dig, 10) {
            string T = S;
            T += (char)('0' + dig);
            ans += go(T);

        }
    } else {
        string T = S;
        T += original[id];
        ans += go(T);
    }

    return ans;
}

int32_t main() {
    // while (cin >> original)
    {
        cin >> original;
        N = original.size();
        // cout << original << '\n';

        int ans = 0;
        if (original[0] == '_' || original[0] == 'X') {
            F0R (dig, 10) {
                string S;
                S += (char)('0' + dig);
                ans += go(S);
            }
        } else {
            string S;
            S += original[0];
            ans += go(S);
        }

        cout << ans << '\n';
    }
}
