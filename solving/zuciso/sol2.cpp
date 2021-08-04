#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define zuciso ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
#define int long long
#define INF 1000000000000000005
#define pb push_back
#define pi 3.1415926
#define MAX 1000000
#define MAX_N 1000000
#define N 1500005
#define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout)
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
const int inf = 1e18;

//static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


inline int rand(int l, int r) {
//    std::uniform_int_distribution<int> uid(l, r);
//    return uid(rng);
    return l + rand() % (r - l + 1);
}
ll fpow(ll x, ll y, ll p = MOD) {
    x = x%p; ll sum = 1; while(y) {
        if(y&1)sum = sum*x; sum %= p; y = y>>1; x = x*x; x %= p;
    }return sum;
}
ll fact[3000007] = {0};
void facto() {
    fact[0] = 1; fact[1] = 1; for(int i = 2; i < 3000007; i++)fact[i] = (fact[i-1]*i)%MOD;
}
ll ncr(ll n, ll r) {
    if(r>n)return 0;
    ll res = 1; res = fact[n]; res = (res*(fpow(fact[r], MOD-2)))%MOD; res = (res*(fpow(fact[n-r], MOD-2)))%MOD; return res;
}
ll npr(ll n, ll r) {
    if(r>n)return 0;
    ll res = 1; res = fact[n]; res = (res*(fpow(fact[n-r], MOD-2)))%MOD; return res;
}
ll modmul(ll x, ll y) {
    return (x*y)%MOD;
}
ll inv(ll x, ll p=MOD){
    return fpow(x,MOD-2);
}
ll modadd(ll x, ll y) {
    return (x+y)%MOD;
}
ll modsub(ll x, ll y) {
    return (x-y+MOD)%MOD;
}
ll xx[4] = {1,0,-1,0};
ll yy[4] = {0,1,0,-1};
using namespace std;

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

class Trie;
class Node{
    vector<Node*> next;
    ll uid;
    friend class Trie;
    Node(){
        next.resize(26, NULL);
    }
};
class Trie{
    Node* head;
    ll idx;
public:
    Trie(){
        head = new Node();
        idx = 0;
        head -> uid = idx;
    }
    void _insert(const string& s, vector<ll>& uids, ll& ptr, Node* curr){

        uids.push_back(curr -> uid);

        if(ptr == s.size()) return;

        if(curr -> next[s[ptr] - 'a'] == NULL){
            curr -> next[s[ptr] - 'a'] = new Node();
            curr -> next[s[ptr] - 'a'] -> uid = ++idx;
        }
                //cout<<s<<endl;

        curr = curr -> next[s[ptr] - 'a'];
        ptr++;
        _insert(s, uids, ptr, curr);
    }
    void insert(const string& s, vector<ll>& uids){
        ll ptr = 0;
        _insert(s, uids, ptr, head);
    }
};

vector<vector<int>> preid(100001),sufid(100001);
map<pair<int,int>,int > num,den;
void solve(){
    int n,x;
    int ans=0;
    cin>>n>>x;
    string s[n];
    Trie prefixt,sufixt;
    for(int i=0;i<n;i++){
        cin>>s[i];
        prefixt.insert(s[i],preid[i]);
        reverse(s[i].begin(),s[i].end());
        sufixt.insert(s[i],sufid[i]);
       reverse(sufid[i].begin(),sufid[i].end());



    }
    map<pair<int,int> , int> cnt;
    for(int i=0;i<n;i++){
        int len=s[i].size()+1;
        map<pair<int,int> ,int> mp;
        int tot=0;
        for(int j=1;j<len;j*=x){
            for(int k=0;k+j<len;k++){
                //if(k+j>n+1)break;
                int yy=sufid[i][(k+j)];
                int xx=preid[i][k];
                mp[{xx,yy}]=1;
                tot++;
            }
        }
        for(auto it:mp){
            if(cnt[it.first]==0){
                num[it.first]=1,den[it.first]=1;
            }
            cnt[it.first]++;
                num[it.first]=(num[it.first]*(tot%MOD+it.second%MOD)%MOD)%MOD;
                den[it.first]=(den[it.first]*tot)%MOD;
        }
    }
    int tupow=fpow(2,n);
    for(auto it:num){
        int xxx = (den[it.first] * tupow) % MOD;
        int yyy = (num[it.first] * inv(xxx)) % MOD;
        yyy = ((yyy-inv(tupow))%MOD+MOD) %MOD;
        ans=  (ans+yyy)%MOD;


    }
    cout<<ans<<endl;

}


void hello() {
	const string hello = "HELLO WORLD\n";
	cout << hello << endl;
}


signed main() {
     // test
    // freopen("input00.txt", "r", stdin);
      solve();
}

