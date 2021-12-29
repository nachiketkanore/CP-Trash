/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 December 2021 03:51:01 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ { $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template <class T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int dp[8][11][25][2];

int32_t main() {
  string S;
  while (cin >> S) {
    const int N = S.size();
    memset(dp, -1, sizeof(dp));

    auto hash = [](char ch) {
        if (ch == 'a') return 10;
        assert('0' <= ch && ch <= '9');
        return ch-'0';
    };

    function<int(int, char, int, bool)> go = [&](int id, char x_value, int val_mod, bool leading_zero) {
        if (id == N) {
            if (val_mod) return 0;
            if (N > 1 && leading_zero) return 0;
            return 1;
        }

        int &ans = dp[id][hash(x_value)][val_mod][leading_zero];
        if (~ans) return ans;
        ans = 0;

        if (S[id] == '_') {
            F0R (dig,10) {
                ans += go(id + 1, x_value, (val_mod * 10 + dig) % 25, leading_zero || (id == 0 && dig == 0));
            }
        } else if (S[id] == 'X') {
            F0R (dig,10) {
                char n_x_value;
                if (x_value == 'a') n_x_value = (char)('0' + dig);
                else {
                    if (x_value-'0' != dig) continue;
                    n_x_value = (char)('0' + dig);
                }
                ans += go(id + 1, n_x_value, (val_mod * 10 + dig) % 25, leading_zero || (id == 0 && dig == 0));
            }
        } else {
            assert('0' <= S[id] && S[id] <= '9');
            int dig = S[id]-'0';
            ans += go(id + 1, x_value, (val_mod * 10 + dig) % 25, leading_zero || (id == 0 && dig == 0));
        }
        return ans;
    };

    int ans = go(0, 'a', 0, false);
    cout << ans << '\n';
  }
}
