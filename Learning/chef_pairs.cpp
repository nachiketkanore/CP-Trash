#include <bits/stdc++.h>
#define initrand mt19937 mt_rand(time(0));
#define rand mt_rand()
#define MOD 1000000007
#define INF 1000000000
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define lz lazup(l, u, i);
using namespace std;
const int N = 1e5 + 5;
long long qans[N];
int qd[N];
vector<int> adj[N];
vector<int> qn[N];
int ind[N];
map<pair<int, int>, int> mp[N];
void dfs(int i, int p, int d){
    int bigC = i;
    int bigSize = 0;
    for(int j: adj[i]){
        if(j==p) continue;
        dfs(j, i, d+1);
        if((int)mp[ind[j]].size() > bigSize){
            bigC = j;
            bigSize = mp[ind[j]].size();
        }
    }
    ind[i] = i;
    int impind = ind[bigC];
    ind[i] = impind;
    for(int k: qn[i]){
        qans[k] += mp[impind][{qd[k] + d, k}];
    }
    for(int k: qn[i]){
        mp[impind][{d, k}] ++;
    }
    for(int x: adj[i]){
        if(x==p || x==bigC) continue;
        for(pair<pair<int, int>, int> k: mp[ind[x]]){
            qans[k.first.second] += (((long long) k.second) * ((long long)mp[impind][{qd[k.first.second] + 2*d - k.first.first, k.first.second}]));
        }
        for(pair<pair<int, int>, int> k: mp[ind[x]]){
            mp[impind][k.first] += k.second;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1;i<=n;i++){
            adj[i].clear();
            mp[i].clear();
            qn[i].clear();
            qans[i] = qd[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int x = 1; x <= q; x++) {
            int k, d;
            cin >> k >> d;
            qd[x] = d;
            for (int j = 0; j < k; j++) {
                int u;
                cin >> u;
                qn[u].push_back(x);
            }
        }
        dfs(1, 1, 0);
        for (int x = 1; x <= q; x++) cout << qans[x] << '\n';
    }

}
