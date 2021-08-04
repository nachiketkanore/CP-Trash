#include <bits/stdc++.h>

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

int is_power(int n, int k) {
    // checks if n = p^k
    int x = pow((long double)n, 1. / k);
    FOR (p,x-2,x+2) if (p > 1) {
        int prod = 1;
        FOR (j,1,k) prod *= p;
        if (prod == n) return p;
    }
    return -1;
}


int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> done(n, false);
    map<int,int> pf;
    map<int,int> cpf;
    F0R (i,n) {
        cin >> a[i];
        int four = is_power(a[i], 4);
        if (~four) {
            pf[four] += 4;
            done[i] = true;
            continue;
        }
        int three = is_power(a[i], 3);
        if (~three) {
           pf[three] += 3;
           done[i] = true;
           continue;
        }
        int two = is_power(a[i], 2);
        if (~two) {
           pf[two] += 2;
           done[i] = true;
           continue;
        }
    }
    F0R (i,n) {
        if (done[i]) continue;
        F0R (j,n) {
            int g = __gcd(a[i], a[j]);
            if (g == 1 || a[i] == a[j]) continue;
            int one = g, two = a[i] / g;
            pf[one] += 1;
            pf[two] += 1;
            done[i] = true;
            break;
        }
        if (!done[i]) {
            cpf[a[i]]++;
        }
    }
    const int MOD = 998244353;
    int ans = 1;
    for (auto [p, e]: pf) ans = ans * (e + 1) % MOD;
    for (auto [p, e]: cpf) {
        ans = ans * (e + 1) % MOD;
        ans = ans * (e + 1) % MOD;
    }
    cout << ans << endl;
}

