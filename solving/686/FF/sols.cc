#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_lev = 18;

template<typename T, int z = 1>
struct sparse_table {
    int num[max_n];
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = z * a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
        for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
            for (int j = i; j <= n && j < i * 2; ++j) {
                num[j] = x;
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return z * inf;
        }
        int lev = num[r - l + 1];
        return z * min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};


int t, n, a[max_n];
sparse_table<int, 1> mn;
sparse_table<int, -1> mx;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        mn.init(n, a);
        mx.init(n, a);
        int x = 0, pos = n - 1;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            x = max(x, a[i]);
            while (pos >= 0 && a[pos] < x) {
                --pos;
            }
            if (pos - 1 <= i || a[pos] != x) {
                continue;
            }
            int j = pos;
            for (int k = max_lev - 1; k >= 0; --k) {
                int nj = j - (1 << k);
                if (i + 1 < nj && mn.get_min(i + 1, nj - 1) <= x && mx.get_min(nj, n - 1) == x) {
                    j = nj;
                }
            }
            //cout << i << " " << j << ": " << x << endl;
            if (mn.get_min(i + 1, j - 1) == mx.get_min(j, n - 1) && x == mx.get_min(j, n - 1)) {
                printf("YES\n%d %d %d\n", i + 1, j - i - 1, n - j);
                ok = true;
                break;
            }
        }
        if (!ok) {
            puts("NO");
        }
    }
    return 0;
}



#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, a[N];
pii tree[4 * N];

pii add(const pii &a, const pii &b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = {a[l], a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = add(tree[2 * i + 1], tree[2 * i + 2]);
}
pii query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return {INT_MAX, INT_MIN};
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return add(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
bool check(int l, int r) {
    if(l <= 1 || r >= n) return false;
    int mx1 = query(0, 1, n, 1, l - 1).second;
    int mn = query(0, 1, n, l, r).first;
    int mx2 = query(0, 1, n, r + 1, n).second;
    if(mx1 == mn && mx1 == mx2) {
        cout << "YES" << '\n';
        cout << l - 1 << ' ' << r - l + 1 << ' ' << n - r << '\n';
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n;
        map<int, vi> ma;
        rep(i, 1, n + 1) {
            cin >> a[i];
            ma[a[i]].push_back(i);
        }
        int minpos = n, maxpos = -1;
        vector<pair<int, vi>> ve(all(ma));
        int mx = *max_element(a + 1, a + n + 1);
        if(sz(ma[mx]) >= 3) {
            cout << "YES" << '\n';
            int pos = ma[mx][1];
            cout << pos - 1 << ' ' << 1 << ' ' << n - pos << '\n';
            goto hell;
        }
        build(0, 1, n);
        reverse(all(ve));
        for(auto &pa : ve) {
            int pos1 = pa.second[0];
            int pos2 = pa.second.back();
            minpos = min(minpos, pos1);
            maxpos = max(maxpos, pos2);
            if(check(minpos, maxpos)) goto hell;
            if(check(minpos - 1, maxpos)) goto hell;
            if(check(minpos, maxpos + 1)) goto hell;
        }
        cout << "NO" << '\n';
        hell:;
    }
}