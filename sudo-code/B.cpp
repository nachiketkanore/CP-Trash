/**
 *    Author: Nachiket Kanore
 *    Created: Monday 08 November 2021 07:11:01 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
  $() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
} $;

template <class T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int INF = 1e18;

int32_t main() {
  int T;
  cin >> T;
  while (T--) {
    int M, X;
    cin >> M >> X;
    int ans = 0;
    FOR(one, 0, M) {
      int two = X - one;
      if (two >= 0 && two <= M) {
        cmax(ans, abs(one - two));
      }
    }
    cout << ans << '\n';
  }
}
