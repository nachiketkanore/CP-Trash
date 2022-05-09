/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 May 2022 05:13:23 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

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
		ret[i] = (round(fv[i].real()));
	return ret;
}
} // namespace fft

const int MX = 1e5;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Sa, Sb, Sc, Sd, K;
	cin >> Sa >> Sb >> Sc >> Sd >> K;
	vector<int> A(MX + 1), B(MX + 1), C(MX + 1), D(MX + 1);
	F0R(i, Sa) {
		int u;
		cin >> u;
		A[u]++;
	}
	F0R(i, Sb) {
		int u;
		cin >> u;
		B[u]++;
	}
	F0R(i, Sc) {
		int u;
		cin >> u;
		C[u]++;
	}
	F0R(i, Sd) {
		int u;
		cin >> u;
		D[u]++;
	}
	vector<int> sum_AB = fft::multiply(A, B);
	FOR(i, 1, sz(sum_AB) - 1) {
		sum_AB[i] += sum_AB[i - 1];
	}
	vector<int> sum_CD = fft::multiply(C, D);

	auto count_products_less_than_equal_to = [&](int prod) {
		int cnt = 0;
		FOR(y, 0, sz(sum_CD) - 1) {
			if (sum_CD[y] == 0)
				continue;
			int x = y > 0 ? prod / y : sz(sum_AB) - 1;
			if (x >= sz(sum_AB))
				x = sz(sum_AB) - 1;
			assert(x < sz(sum_AB));
			cnt += sum_AB[x] * sum_CD[y];
			if (cnt >= K)
				return K;
		}
		return cnt;
	};

	int lo = 0, hi = 1e12;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (count_products_less_than_equal_to(mid) >= K) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	assert(~ans);
	cout << ans;
	return 0;
}
