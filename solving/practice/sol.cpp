/**
 *	Author: Nachiket Kanore
 *	Created: Saturday 26 June 2021 01:32:17 PM IST
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
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

int dfs(vector<vector<int>>& grid, int n, int m, int i, int j){
  if(i>=n || j>=m ||i<0||j<0 || grid[i][j] <= 0)return 0;
  int temp =grid[i][j];
  int cost = grid[i][j];
  grid[i][j] = -1;
  cost+=max({dfs(grid,n,m,i+1,j),dfs(grid,n,m,i-1,j),dfs(grid,n,m,i,j+1),dfs(grid,n,m,i,j-1)});
  grid[i][j] = temp;
  return cost;
}
int getMaximumGold(vector<vector<int>>& grid) {
  int n = grid.size() ;
  int m = grid[0].size();
  int ans = 0;
  for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
        if(grid[i][j]){
               //cout << "Start : " << i <<" " << j << endl;
           ans = max(ans,dfs(grid,n,m,i,j));
       }
   }
}
return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    F0R (i,n) F0R (j,m) cin >> mat[i][j];
    cout << getMaximumGold(mat) << '\n';
}

int32_t main() {
    int T; cin >> T; while (T--) solve();
}
