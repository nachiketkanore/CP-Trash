class Solution {
  public:
  int timer = 0;
  vector<vector<int>> adj;
  vector<int> parent, tin, tout, dist, pref, suff;
  
  void dfs(int u, int par, int d) {
      parent[u] = par;
      tin[u] = ++timer;
      dist[u] = d;
      pref[timer] = dist[u];
      suff[timer] = dist[u];
      for (int v: adj[u]) {
          if (v^par) {
              dfs(v, u, d + 1);
          }
      }
      tout[u] = timer;
  }
  
    vector<int> solve(int N, int Q, vector<vector<int> > &Edge,
                      vector<vector<int> > &query) {
        adj.resize(N);
        parent.resize(N);
        tin.resize(N);
        tout.resize(N);
        dist.resize(N);
        pref.resize(N + 2);
        suff.resize(N + 2);
        
        for (auto it: Edge) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1, 0);
        for (int i = 2; i <= N; i++) {
            pref[i] = max(pref[i], pref[i - 1]);
        }
        for (int i = N - 1; i >= 1; i--) {
            suff[i] = max(suff[i], suff[i + 1]);
        }
        
        vector<int> ans;
        
        for (auto it: query) {
            int u = it[0], v = it[1];
            if (dist[u] > dist[v]) swap(u, v);
            assert(parent[v] == u);
            // u --> v
            int L = tin[v], R = tout[v];
            int best = max(pref[L - 1], suff[R + 1]);
            ans.push_back(best);
        }    
        
        return ans;
    }
};
