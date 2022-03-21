#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = 3e5 + 5;

int n, m, node = 1, maxdist;
int tim = 0, grp = 1;
int u[N], v[N], comp[N];
bool vis[N], vis2[N], isBridge[M];
int tin[N], tout[N], minAncestor[N];
queue<int> Q[N];
vector<pair<int, int> > g[N];
vector<int> tree[N], vertices[N]; //Tree stores Bridge Tree, vertices stores the nodes in each component

void dfs(int k, int par)
{
    vis[k]=1;
    tin[k]=++tim;
    minAncestor[k]=tin[k];
    for(auto it:g[k])
    {
        if(it.first==par)
            continue;
        if(vis[it.first])
        {
            minAncestor[k]=min(minAncestor[k], tin[it.first]);
            continue;
        }
        dfs(it.first, k);
        minAncestor[k]=min(minAncestor[k], minAncestor[it.first]);
        if(minAncestor[it.first]>tin[k])
            isBridge[it.second]=1;
    }
    tout[k]=tim;
}

void dfs2(int k)
{
    int comp=grp;
    Q[comp].push(k);
    vis2[k]=1;
    while(!Q[comp].empty())
    {
        int u=Q[comp].front();
        Q[comp].pop();
        vertices[comp].push_back(u);
        for(auto it:g[u])
        {
            int v=it.first;
            int edgeidx=it.second;
            if(vis2[v])
                continue;
            if(isBridge[edgeidx])
            {
                grp++;
                tree[comp].push_back(grp);
                tree[grp].push_back(comp);
                dfs2(v);
            }
            else
            {
                Q[comp].push(v);
                vis2[v]=1;
            }
        }
    }
}

void create_bridge_tree() {
    dfs(1, 0);
    dfs2(1);
}

void GO(int u, int par, int dist, int &end1, int &diam) {
    if (diam < dist) {
        diam = dist;
        end1 = u;
    }

    for (int v : tree[u]) if(par != v) GO(v, u, dist + 1, end1, diam);
}

int diameter() {
    int end1 = 0;
    int diam = 0;

    GO(1,1,0,end1,diam);
    GO(end1,0,0,end1,diam);

    return diam;
}

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> n;
		int id = 1;
		int A[n + 1];
		vector<pair<int,int>> edges;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			for (int j = 1; j < i; j++) {
				if (__gcd(A[i], A[j]) > 1) {
					edges.push_back({i, j});
				}
			}
		}
		m = edges.size();
		for (auto [from, to]: edges) {
			u[id] = from;
			v[id] = to;
			g[u[id]].push_back({v[id], id});
			g[v[id]].push_back({u[id], id});
			id++;
		}
		for (int i = 1; i <= n; i++) {
			see(i, g[i]);
		}
		create_bridge_tree();
		for (int i = 1; i <= n; i++) {
			see(i, vertices[i]);
		}

		cout << n - diameter() << '\n';
		for (int i = 1; i <= m; i++) {
			g[u[i]].clear();
			g[v[i]].clear();
		}
	}
}
// Majha approach asa ahe:
// Create a graph G from array A such that
// i and j have edge if gcd(A[i], A[j]) > 1
//
// Now, in this graph we want to find max length path
