#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define all(v) (v.begin(), v.end())

#define row vector<long long>
#define matrix vector<row>
#define ROWS(v) (v).size()
#define COLS(v) (v)[0].size()

#define DBG1(x) cerr << #x << ":" << (x) << '\n';
#define DBG2(x, y) cerr << #x << ":" << (x) << "  " << #y << ":" << (y) << '\n';
#define DBG3(x, y, z) cerr << #x << ":" << (x) << "  " << #y << ":" << (y) << "  " << #z << ":" << (z) << '\n';

typedef long long lld;

const int N = 1e5 + 9, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
char s[N];

matrix TR[N << 2], arr[2];
bool lazy[N << 2];
matrix ans(2, row(2, 0)), c(2, row(2, 0));
matrix identity = { { 1, 0 }, { 0, 1 } };

matrix mul(const matrix& a, const matrix& b) {
	c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
	return c;
}

inline void edit(int p) {
	swap(TR[p][0][0], TR[p][1][1]);
	swap(TR[p][0][1], TR[p][1][0]);
}

inline void push(int p) {
	lazy[p] = 0;
	edit(p * 2);
	lazy[p * 2] ^= 1;
	edit(p * 2 + 1);
	lazy[p * 2 + 1] ^= 1;
}

matrix build(int l = 0, int r = n - 1, int p = 1) {
	if (l == r)
		return TR[p] = arr[s[l] - 'A'];
	int m = (l + r) >> 1;
	return TR[p] = mul(build(l, m, p * 2), build(m + 1, r, p * 2 + 1));
}

matrix update(int l, int r, int ql, int qr, int p = 1) {
	if (r < ql || l > qr)
		return TR[p];
	if (l >= ql && r <= qr) {
		edit(p);
		lazy[p] ^= 1;
		return TR[p];
	}
	if (lazy[p])
		push(p);
	int m = (l + r) >> 1;
	return TR[p] = mul(update(l, m, ql, qr, p * 2), update(m + 1, r, ql, qr, p * 2 + 1));
}

matrix get(int l, int r, int ql, int qr, int p = 1) {
	if (r < ql || l > qr)
		return identity;
	if (l >= ql && r <= qr)
		return TR[p];
	if (lazy[p])
		push(p);
	int m = (l + r) >> 1;
	return mul(get(l, m, ql, qr, p * 2), get(m + 1, r, ql, qr, p * 2 + 1));
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// fastin;
	scanf("%d %d", &n, &q);
	scanf("%s", s);

	arr[0] = { { 1, 0 }, { 1, 1 } };

	arr[1] = { { 1, 1 }, { 0, 1 } };

	build();

	while (q--) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		--l, --r;
		if (t == 1)
			update(0, n - 1, l, r);
		else {
			lld a, b;
			scanf("%lld %lld", &a, &b);
			ans[0][0] = a;
			ans[0][1] = b;
			ans = mul(ans, get(0, n - 1, l, r));
			printf("%lld %lld\n", ans[0][0], ans[0][1]);
		}
	}

	return 0;
}
