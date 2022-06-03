/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 02 June 2022 10:07:59 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MOD = 1e9 + 7;
struct mi {
	using ll = long long;
	ll v;
	explicit operator ll() const {
		return v;
	}
	mi() {
		v = 0;
	}
	mi(ll _v) {
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0)
			v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b);
	}
	friend bool operator<(const mi& a, const mi& b) {
		return a.v < b.v;
	}
	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD)
			v -= MOD;
		return *this;
	}
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0)
			v += MOD;
		return *this;
	}
	mi& operator*=(const mi& m) {
		v = v * m.v % MOD;
		return *this;
	}
	mi& operator/=(const mi& m) {
		return (*this) *= inv(m);
	}

	friend mi pow(mi a, ll p) {
		mi ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1)
				ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mi operator-() const {
		return mi(-v);
	}
	mi& operator++() {
		return *this += 1;
	}
	mi& operator--() {
		return *this -= 1;
	}
	mi operator++(int32_t) {
		mi temp;
		temp.v = v++;
		return temp;
	}
	mi operator--(int32_t) {
		mi temp;
		temp.v = v--;
		return temp;
	}
	friend mi operator+(mi a, const mi& b) {
		return a += b;
	}
	friend mi operator-(mi a, const mi& b) {
		return a -= b;
	}
	friend mi operator*(mi a, const mi& b) {
		return a *= b;
	}
	friend mi operator/(mi a, const mi& b) {
		return a /= b;
	}
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v;
		return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x;
		is >> x;
		m.v = x;
		return is;
	}
};

struct Matrix {
	mi mat[2][2];

	Matrix(bool identity = false) {
		memset(mat, 0, sizeof(mat));
		if (identity) {
			F0R(i, 2) mat[i][i] = 1;
		}
	}

	friend Matrix operator*(const Matrix& A, const Matrix& B) {
		Matrix res;
		F0R(i, 2) F0R(j, 2) F0R(k, 2) res.mat[i][j] += A.mat[i][k] * B.mat[k][j];
		return res;
	}

	void print() {
		cout << "\n-------------\n";
		F0R(i, 2) F0R(j, 2) cout << mat[i][j] << " \n"[j == 1];
		cout << "\n-------------\n";
	}
};

const int _ = 1e5 + 5;
Matrix T[2]; // T[0] is matrix for 'A', T[1] is matrix for 'B'
char S[_];

class node {
	public:
	static const int inf = 1e18;
	int mn, mx, sum;
	Matrix now, other;

	node(char ch) {
		sum = 0;
		if (ch == 'A') {
			now = T[0];
			other = T[1];
		} else {
			now = T[1];
			other = T[0];
		}
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
		now = Matrix(1);
		other = Matrix(1);
	}

	Matrix get_now() {
		// return sum % 2 == 0 ? now : other;
		return now;
	}

	Matrix get_other() {
		// return sum % 2 == 0 ? other : now;
		return other;
	}
};

struct segtree {
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n) {
		N = n;
		st.resize((N << 2) + 2);
		cLazy.assign((N << 2) + 2, false);
		lazy.assign((N << 2) + 2, 0);
		build(1, 1, N);
	}

	// Write reqd merge functions
	void merge(node& ret, node& left, node& right) {
		// ret.sum = left.sum + right.sum;
		ret.now = right.get_now() * left.get_now();
		ret.other = right.get_other() * left.get_other();
	}

	// Handle lazy propagation appriopriately
	void propagate(int u, int L, int R) {
		// Propagate down?
		if (L != R) {
			cLazy[u * 2] = 1;
			cLazy[u * 2 + 1] = 1;

			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			lazy[u * 2] += lazy[u];
			lazy[u * 2 + 1] += lazy[u];
		}

		// Updating the range [L, R] with lazy[u]
		{
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			st[u].sum += (R - L + 1) * lazy[u];
			st[u].sum %= 2;
			if (st[u].sum) {
				swap(st[u].now, st[u].other);
				st[u].sum = 0;
			}
			st[u].mx += lazy[u];
			st[u].mn += lazy[u];
		}
		cLazy[u] = 0;
		lazy[u] = 0;
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(S[L]);
			return;
		}
		int M = (L + R) / 2;
		build(u * 2, L, M);
		build(u * 2 + 1, M + 1, R);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j < L || i > R)
			return node();
		if (i <= L && R <= j)
			return st[u];
		int M = (L + R) / 2;
		node left = Query(u * 2, L, M, i, j);
		node right = Query(u * 2 + 1, M + 1, R, i, j);
		node ret;
		ret.now = right.get_now() * left.get_now();
		return ret;
	}

	node pQuery(int u, int L, int R, int pos) {
		if (cLazy[u])
			propagate(u, L, R);
		if (L == R)
			return st[u];
		int M = (L + R) / 2;
		if (pos <= M)
			return pQuery(u * 2, L, M, pos);
		else
			return pQuery(u * 2 + 1, M + 1, R, pos);
	}

	void Update(int u, int L, int R, int i, int j, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j < L || i > R)
			return;
		if (i <= L && R <= j) {
			// Default range update operation is :
			// adding val to all elements in range [...]
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
			return;
		}
		int M = (L + R) / 2;
		Update(u * 2, L, M, i, j, val);
		Update(u * 2 + 1, M + 1, R, i, j, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	void pUpdate(int u, int L, int R, int pos, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (L == R) {
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
			return;
		}
		int M = (L + R) / 2;
		if (pos <= M)
			pUpdate(u * 2, L, M, pos, val);
		else
			pUpdate(u * 2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node query(int pos) {
		return pQuery(1, 1, N, pos);
	}

	node query(int l, int r) {
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int val) {
		pUpdate(1, 1, N, pos, val);
	}

	void update(int l, int r, int val) {
		Update(1, 1, N, l, r, val);
	}
} st;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N) cin >> S[i];

	T[0].mat[0][0] = T[0].mat[0][1] = T[0].mat[1][1] = 1;
	T[1].mat[0][0] = T[1].mat[1][0] = T[1].mat[1][1] = 1;

	st.init(N);

	while (Q--) {
		int type, L, R, A, B;
		cin >> type >> L >> R;

		if (type == 1) {
			st.update(L, R, 1);
			/* FOR(i, 1, N) {
				cout << st.query(i);
			}
			cout << '\n'; */
		} else {
			cin >> A >> B;
			/* see("query...");
			see("query...");
			ans.print(); */
			Matrix ans = st.query(L, R).get_now();

			mi ans_A = ans.mat[0][0] * A + ans.mat[0][1] * B;
			mi ans_B = ans.mat[1][0] * A + ans.mat[1][1] * B;

			cout << ans_A << ' ' << ans_B << '\n';
		}
	}

	return 0;
}
