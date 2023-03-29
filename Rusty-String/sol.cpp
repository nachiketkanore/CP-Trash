/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 March 2023 12:18:59 PM IST
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

#include <complex>
const double PI = acos(-1);

namespace fft {
typedef complex<double> base;
void fft(vector<base>& v, bool inv) {
	vector<base> w(v.size());
	for (int i = 2; i <= sz(v); i <<= 1) {
		int bsz = v.size() / i;
		base ang(cos(2 * PI / i), sin(2 * PI / i));
		if (inv)
			ang = base(1, 0) / ang;
		for (int j = 0; j < bsz; j++) {
			for (int k = 0; k < i; k++) {
				w[k] = v[bsz * k + j];
			}
			base pw(1, 0);
			for (int k = 0; k < i / 2; k++) {
				base a = w[2 * k], b = w[2 * k + 1] * pw;
				v[bsz * k + j] = a + b;
				v[bsz * k + j + v.size() / 2] = a - b;
				pw *= ang;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < sz(v); i++) {
			v[i] /= v.size();
		}
	}
}
vector<int> multiply(vector<int>& v, vector<int>& w) {
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 1;
	while (n < max(sz(v), sz(w)))
		n <<= 1;
	n <<= 1;
	fv.resize(n);
	fw.resize(n);
	fft(fv, 0);
	fft(fw, 0);
	for (int i = 0; i < n; i++)
		fv[i] *= fw[i];
	fft(fv, 1);
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
		ret[i] = (round(fv[i].real()) > 0); // remove to get actual coefficients
	return ret;
}
} // namespace fft

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> V(2 * n + 1), K(2 * n + 1);
	F0R(i, n) {
		if (s[i] == 'V') {
			V[i] = 1;
		}
		if (s[i] == 'K') {
			K[-i + n] = 1;
		}
	}
	vector<int> product = fft::multiply(V, K);
	vector<bool> possible_distances(sz(product) + 1, false);
	F0R(dist, sz(product)) {
		if (product[dist]) {
			int d = abs(dist - n);
			possible_distances[d] = true;
		}
	}

	vector<int> ans;
	FOR(p, 1, n) {
		bool good = true;
		for (int m = p; m <= sz(product); m += p) {
			good &= !possible_distances[m];
		}
		if (good)
			ans.push_back(p);
	}

	cout << sz(ans) << '\n';
	for (int p : ans)
		cout << p << ' ';
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
