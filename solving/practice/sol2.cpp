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

int checker = 0;

// if some number is involved then cleverly try to process the number .. 
// for ex:
// if number 3 is involved try to go through the middle element .. or if 2 is involved try to binary search
// or search the second element;
int n,x,y;
const int N = 3001;
int a[N], b[N], dp[N][N];

int f(int id, int X) {
    if(X > x) return inf;
    if(id >= n) {
        if(n-X > y) return inf;
        return 0;
    }
    if(dp[id][X] != -1) return dp[id][X];
    int ans = min(a[id]+f(id+1,X+1),b[id]+f(id+1,X));
    return dp[id][X] = ans;
}

void solve() {
    cin>>n>>x>>y;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    memset(dp,-1,sizeof(dp));
    cout<<f(0,0);
}

signed main()
{
    fast;
    //test 
    {
        solve();
    }
    return 0;   
}