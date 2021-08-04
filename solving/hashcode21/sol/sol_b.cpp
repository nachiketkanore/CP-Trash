#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define inf 5e18
#define MOD (int)(1e9 + 7)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                       \
    ios_base ::sync_with_stdio(0); \
    cin.tie(NULL);                 \
    cout.tie(NULL)
using namespace std;
// using namespace __gnu_pbds;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

// oset curr;

void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define see(x...)
#endif
map<string,int> g;
map<int,vector<string>> h;
map<string,int> mp;

int rand(int l, int r) {
    return (l+rand()%(r-l+1));
}

void solve() {
    int d,i,s,v,f;
    cin>>d>>i>>s>>v>>f;
    for(int i=0;i<s;i++) {
        int u,v,t;
        string str;
        cin>>u>>v>>str>>t;
        g[str]=v;
        h[v].pb(str);
    }
    for(int i=0;i<v;i++) {
        int x;
        cin>>x;
        while(x--) {
            string s;
            cin>>s;
            mp[s]++;
        }
    }
    vector<pair<int,pair<string,int>>> V;
    for(auto i : mp) V.pb({i.second,{i.first,g[i.first]}});
    sort(rall(V));
    int cnt = 0;
    map<int,vector<string>> mpp;
    for(auto i : V) {
        mpp[i.second.second].pb(i.second.first);
    }
    for(auto i : mpp) {
        if(i.second.size()) cnt++;
    }
    cout<<cnt<<"\n";
    for(auto i : mpp) {
        cout<<i.first<<"\n";
        cout<<i.second.size()<<"\n";
        for(auto j : i.second) cout<<j<<" "<<1<<"\n";
    }
}

signed main()
{
    fast;
    // test
    {
        solve();
    }
    return 0;   
}