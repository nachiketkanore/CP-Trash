#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define ll long long
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 2e7 + 2;
const ll inf = 1e18;

int n, add_del, copy_;
vector<pair<int,int>> g[N+1];
int larger, smaller;
ll d[N];

void dijkstra(int s) {
    FOR (i,1,N) d[i] = inf;
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : g[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == smaller)
                    q.push_front(u);
                else
                    q.push_back(u);
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    cin >> n >> add_del >> copy_;

    smaller = min(add_del, copy_);
    larger = max(add_del, copy_);
    
    g[0].push_back({1,add_del});

    FOR(i,1,n) {
        // add
        int j = i + 1;
        if (j < N)
		g[i].push_back({j,add_del});
        // delete
        j = i - 1;
        if (j >= 0)
		g[i].push_back({j,add_del});
        // copy
        j = i + i;
        if (j < N)
		g[i].push_back({j, copy_});
    }   
    
    dijkstra(0);
    cout << d[n] << '\n';

}
