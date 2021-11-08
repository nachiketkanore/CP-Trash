/**
 *    Author: Nachiket Kanore
 *    Created: Monday 08 November 2021 07:16:55 PM IST
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

int32_t main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int to[N], ans[N];
    bool vis[N];
    memset(vis, false, sizeof(vis));
    F0R(i, N) {
      cin >> to[i];
      to[i]--;
    }
    F0R(i, N) {
      if (vis[i])
        continue;
      int cycle_length = 0;
      int j = i;
      vector<int> cycle;
      while (vis[j] == false) {
        cycle_length++;
        cycle.push_back(j);
		vis[j] = true;
        j = to[j];
      }
      for (int x : cycle) {
        ans[x] = cycle_length;
      }
    }
    F0R(i, N) { cout << ans[i] << ' '; }
    cout << '\n';
  }
}
