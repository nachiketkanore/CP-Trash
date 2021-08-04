#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;


map<int,int> dp[60];
class Solution {
    public:
    vector<int> vals;
    bool go(int id, int rem) {
        if (rem <= 0) return rem == 0;
        if (id == (int)vals.size()) return false;
        if (dp[id].count(rem))
            return dp[id][rem];
    
        int ans = go(id + 1, rem) || go(id + 1, rem - vals[id]);
        dp[id][rem] = ans;
        return ans;
    }
    bool solve(int n) {
        vals.push_back(1);
        while (vals.back() < n) {
            vals.push_back(vals.back() * (vals.size() + 1));
        }
        return go(0,n);
    }
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	FOR(n,1,100) {
		Solution s;
		int ans = s.solve(n);

		if (ans) {
			cout << n << '\n';
		}
	}	
}