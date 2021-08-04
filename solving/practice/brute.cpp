#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

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

const int N = 20, mod = 1e9 + 7, inf = 1e18;

string A, B;
int n, dp[N][2][2];
int have;

int go(int pos, bool bigA, bool smallB){
    if(pos >= n)
        return 1;

    int &ans = dp[pos][bigA][smallB];
    if(~ans)
        return ans;
    ans = 0;
    for(int i = 0; i < 10; i++) if (have >> i & 1) {
        if(!bigA && i < A[pos] - '0')   continue;
        if(!smallB && i > B[pos] - '0') continue;

        ans += go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'));
    }
    return ans;
}

int cnt_range(int one, int two) {
    memset(dp, -1, sizeof(dp));
    A = to_string(one);
    B = to_string(two);
    reverse(A.begin(), A.end());
    while(sz(A) < sz(B))
        A.push_back('0');
    reverse(A.begin(), A.end());
    n = sz(B);
    int ans = 0;

    for(int i = 0; i < 10; i++) if (have >> i & 1) {
        if(i < A[0] - '0')  continue;
        if(i > B[0] - '0')  continue;

        ans += go(1, i > A[0] - '0', i < B[0] - '0');
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    int cnt;
    cin >> cnt;
    while (cnt--) {
        int d;
        cin >> d;
        have |= 1 << d;
    }
    int k;
    cin >> k;
    int lo = 1, hi = 1e18;
    int best = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (cnt_range(1, mid) >= k) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        see(best);
    }
    cout << best << '\n';
}