/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 08 January 2022 02:52:20 PM IST
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

int32_t main() {
    int T = 100;
    // cin >> T;
    // while (T--)
    const int mn = 1e5;
    const int mx = mn + 50;
    FOR (tc, mn, mx)
    {
        int N = tc * 2, K = 1;
        // cin >> N >> K;
        assert(N % 2 == 0);
        vector<int> A(N);
        vector<vector<int>> go;
        F0R (i,N) A[i] = i;
        while (true) {
            if (sz(go) && go.front() == A) break;
            go.push_back(A);
            vector<int> first, second;
            F0R (i,N) {
                if (i % 2)
                    second.push_back(A[i]);
                else
                    first.push_back(A[i]);
            }
            A.clear();
            for (int x: first) A.push_back(x);
            for (int x: second) A.push_back(x);
        }
        cout << "N = " << N << " , cycle length = " << sz(go) << '\n';
        // for (auto row: go) {
        //     for (int x: row) {
        //         cout << x + 1 << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << string(100, '-');
        K %= sz(go);
        // for (int x: go[K]) {
        //     cout << x + 1 << ' ';
        // }
        // cout << '\n';
    }
}
