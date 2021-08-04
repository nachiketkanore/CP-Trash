#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

struct segtree {
    struct data {
        int sum, pref, suff, ans;
    };

    int N;
    vector<data> t;

    segtree(int n) {
        N = n;
        t = vector<data> (N << 2);
    }

    data combine(data l, data r) {
        data res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
        return res;
    }

    data make_data(int val) {
        data res;
        res.sum = val;
        res.pref = res.suff = res.ans = max(0ll, val);
        return res;
    }

    // void build(int a[], int v, int tl, int tr) {
    //     if (tl == tr) {
    //         t[v] = make_data(a[tl]);
    //     } else {
    //         int tm = (tl + tr) / 2;
    //         build(a, v*2, tl, tm);
    //         build(a, v*2+1, tm+1, tr);
    //         t[v] = combine(t[v*2], t[v*2+1]);
    //     }
    // }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = make_data(new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    data query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return make_data(0);
        if (l == tl && r == tr) 
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(query(v*2, tl, tm, l, min(r, tm)), 
                       query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};

vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    const int n = A.size();
    segtree one(n), two(n);
    for (int i = 1; i <= n; i++) {
        int u = A[i-1];
        if (i & 1) {
            one.update(1, 1, n, i, u);
            two.update(1, 1, n, i, -u);
        }
        else {
            one.update(1, 1, n, i, -u);
            two.update(1, 1, n, i, u);
        }
    }
    vector<int> ans;
    for (auto qry : B) {
        int type = qry[0];
        if (type == 1) {
            int id = qry[1], val = qry[2];
            if (id & 1) {
                one.update(1, 1, n, id, val);
                two.update(1, 1, n, id, -val);
            }
            else {
                one.update(1, 1, n, id, -val);
                two.update(1, 1, n, id, val);
            }
        } else {
            int L = qry[1], R = qry[2];
            int best1 = one.query(1, 1, n, L, R).ans;
			int best2 = two.query(1, 1, n, L, R).ans;
			see(L, R, best1, best2);
            ans.push_back(max(best1, best2));
        }
    }
    return ans;
}


int32_t main() {
	vector<int> A = {2, 4, -10, 3, 7};
	vector<vector<int>> B = {
		{2, 1, 2},
		{2, 3, 4},
		{2, 1, 5},
		{2, 2, 3}
	};
	see(solve(A, B));
}
