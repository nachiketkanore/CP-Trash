#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <long long mod> struct modular {
	long long value;
	modular(long long x = 0) {
		value = x % mod;
		if (value < 0)
			value += mod;
	}
	modular& operator+=(const modular& other) {
		if ((value += other.value) >= mod)
			value -= mod;
		return *this;
	}
	modular& operator-=(const modular& other) {
		if ((value -= other.value) < 0)
			value += mod;
		return *this;
	}
	modular& operator*=(const modular& other) {
		value = value * other.value % mod;
		return *this;
	}
	modular& operator/=(const modular& other) {
		long long a = 0, b = 1, c = other.value, m = mod;
		while (c != 0) {
			long long t = m / c;
			m -= t * c;
			swap(c, m);
			a -= t * b;
			swap(a, b);
		}
		a %= mod;
		if (a < 0)
			a += mod;
		value = value * a % mod;
		return *this;
	}
	friend modular operator+(const modular& lhs, const modular& rhs) {
		return modular(lhs) += rhs;
	}
	friend modular operator-(const modular& lhs, const modular& rhs) {
		return modular(lhs) -= rhs;
	}
	friend modular operator*(const modular& lhs, const modular& rhs) {
		return modular(lhs) *= rhs;
	}
	friend modular operator/(const modular& lhs, const modular& rhs) {
		return modular(lhs) /= rhs;
	}
	modular& operator++() {
		return *this += 1;
	}
	modular& operator--() {
		return *this -= 1;
	}
	modular operator++(int) {
		modular res(*this);
		*this += 1;
		return res;
	}
	modular operator--(int) {
		modular res(*this);
		*this -= 1;
		return res;
	}
	modular operator-() const {
		return modular(-value);
	}
	bool operator==(const modular& rhs) const {
		return value == rhs.value;
	}
	bool operator!=(const modular& rhs) const {
		return value != rhs.value;
	}
	bool operator<(const modular& rhs) const {
		return value < rhs.value;
	}
};
template <long long mod> string to_string(const modular<mod>& x) {
	return to_string(x.value);
}
template <long long mod> ostream& operator<<(ostream& stream, const modular<mod>& x) {
	return stream << x.value;
}
template <long long mod> istream& operator>>(istream& stream, modular<mod>& x) {
	stream >> x.value;
	x.value %= mod;
	if (x.value < 0)
		x.value += mod;
	return stream;
}

constexpr long long mod = 998244353;
using mint = modular<mod>;

mint power(mint a, long long n) {
	mint res = 1;
	while (n > 0) {
		if (n & 1) {
			res *= a;
		}
		a *= a;
		n >>= 1;
	}
	return res;
}

vector<mint> fact(1, 1);
vector<mint> finv(1, 1);

mint C(int n, int k) {
	if (n < k || k < 0) {
		return mint(0);
	}
	while ((int)fact.size() < n + 1) {
		fact.emplace_back(fact.back() * (int)fact.size());
		finv.emplace_back(mint(1) / fact.back());
	}
	return fact[n] * finv[k] * finv[n - k];
}

namespace NTT {
mint root;
int base;
int max_base;
vector<mint> roots;
vector<int> rev;

void ensure_base(int nbase) {
	if (roots.empty()) {
		auto tmp = mod - 1;
		max_base = 0;
		while (tmp % 2 == 0) {
			tmp /= 2;
			max_base++;
		}
		root = 2;
		while (power(root, (mod - 1) >> 1) == 1) {
			root += 1;
		}
		root = power(root, (mod - 1) >> max_base);
		base = 1;
		rev = { 0, 1 };
		roots = { 0, 1 };
	}
	if (nbase <= base) {
		return;
	}
	rev.resize(1 << nbase);
	for (int i = 0; i < (1 << nbase); i++) {
		rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
	}
	roots.resize(1 << nbase);
	while (base < nbase) {
		mint z = power(root, 1 << (max_base - 1 - base));
		for (int i = 1 << (base - 1); i < (1 << base); i++) {
			roots[i << 1] = roots[i];
			roots[(i << 1) + 1] = roots[i] * z;
		}
		base++;
	}
}

void ntt(vector<mint>& a) {
	int n = (int)a.size();
	int zeros = __builtin_ctz(n);
	ensure_base(zeros);
	int shift = base - zeros;
	for (int i = 0; i < n; i++) {
		if (i < (rev[i] >> shift)) {
			swap(a[i], a[rev[i] >> shift]);
		}
	}
	for (int k = 1; k < n; k <<= 1) {
		for (int i = 0; i < n; i += 2 * k) {
			for (int j = 0; j < k; j++) {
				mint x = a[i + j];
				mint y = a[i + j + k] * roots[j + k];
				a[i + j] = x + y;
				a[i + j + k] = x - y;
			}
		}
	}
}

vector<mint> multiply(vector<mint> a, vector<mint> b) {
	int need = (int)a.size() + (int)b.size() - 1;
	int nbase = 0;
	while ((1 << nbase) < need) {
		nbase++;
	}
	ensure_base(nbase);
	int sz = 1 << nbase;
	a.resize(sz);
	b.resize(sz);
	ntt(a);
	ntt(b);
	mint inv = mint(1) / mint(sz);
	for (int i = 0; i < sz; i++) {
		a[i] *= b[i] * inv;
	}
	reverse(a.begin() + 1, a.end());
	ntt(a);
	a.resize(need);
	return a;
}
} // namespace NTT

vector<mint> operator*(const vector<mint>& a, const vector<mint>& b) {
	if (a.empty() || b.empty()) {
		return {};
	} else if (min(a.size(), b.size()) < 150) {
		vector<mint> c(a.size() + b.size() - 1);
		for (int i = 0; i < (int)a.size(); i++) {
			for (int j = 0; j < (int)b.size(); j++) {
				c[i + j] += a[i] * b[j];
			}
		}
		return c;
	} else {
		return NTT::multiply(a, b);
	}
}

vector<mint>& operator*=(vector<mint>& a, const vector<mint>& b) {
	return a = a * b;
}

template <typename T, typename U> vector<T> power(const vector<T>& a, const U& b) {
	assert(b >= 0);
	vector<U> binary;
	U bb = b;
	while (bb > 0) {
		binary.emplace_back(bb & 1);
		bb >>= 1;
	}
	vector<T> res = vector<T>{ 1 };
	for (int j = (int)binary.size() - 1; j >= 0; j--) {
		res = res * res;
		res.resize(a.size());
		if (binary[j] == 1) {
			res = res * a;
			res.resize(a.size());
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	const int m = (int)1e5 + 100;
	vector<mint> f(m);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		f[a]++;
	}
	f = power(f, k);
	vector<mint> pref(m + 1);
	mint p = 1 / power(n, k);
	for (int i = 0; i < m; i++) {
		pref[i + 1] = pref[i] + f[i] * p;
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << pref[r + 1] - pref[l] << '\n';
	}
	return 0;
}
