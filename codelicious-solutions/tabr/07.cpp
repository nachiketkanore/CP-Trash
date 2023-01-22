#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const long double eps = 1e-12L;
const long double pi = acosl(-1);

template <typename T> struct Tpoint {
	T x;
	T y;
	Tpoint(T _x = 0, T _y = 0) : x(_x), y(_y) {
	}
	Tpoint& operator+=(Tpoint other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	Tpoint& operator-=(Tpoint other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Tpoint& operator*=(T other) {
		x *= other;
		y *= other;
		return *this;
	}
	Tpoint& operator/=(T other) {
		x /= other;
		y /= other;
		return *this;
	}
	Tpoint operator-() {
		return Tpoint(*this) *= -1;
	}
	Tpoint operator+(Tpoint rhs) {
		return Tpoint(*this) += rhs;
	}
	Tpoint operator-(Tpoint rhs) {
		return Tpoint(*this) -= rhs;
	}
	Tpoint operator*(T rhs) {
		return Tpoint(*this) *= rhs;
	}
	Tpoint operator/(T rhs) {
		return Tpoint(*this) /= rhs;
	}
	bool operator==(Tpoint rhs) {
		return (abs(x - rhs.x) < eps && abs(y - rhs.y) < eps);
	}
	bool operator!=(Tpoint rhs) {
		return (abs(x - rhs.x) > eps || abs(y - rhs.y) > eps);
	}
};
// template <typename T>
// bool operator<(Tpoint<T> a, Tpoint<T> b) {
//     return (abs(a.x - b.x) < eps ? a.y < b.y : a.x < b.x);
//     return (atan2l(a.y, a.x) < atan2l(b.y, b.x));
// }
template <typename T> string to_string(Tpoint<T> a) {
	return "(" + to_string(a.x) + ", " + to_string(a.y) + ")";
}
template <typename T> T dot(Tpoint<T> a, Tpoint<T> b) {
	return a.x * b.x + a.y * b.y;
}
template <typename T> T cross(Tpoint<T> a, Tpoint<T> b) {
	return a.x * b.y - a.y * b.x;
}
template <typename T> T dist2(Tpoint<T> a, Tpoint<T> b) {
	return dot(a - b, a - b);
}
template <typename T> long double dist(Tpoint<T> a, Tpoint<T> b) {
	return sqrtl(dist2(a, b));
}
template <typename T> long double norm(Tpoint<T> a) {
	return sqrtl(dot(a, a));
}
template <typename T> long double arg(Tpoint<T> a) {
	return atan2l(a.y, a.x);
}

using point = Tpoint<long long>;
// using point = Tpoint<long double>;

vector<point> convexhull(vector<point> p, bool vertex_only = true) {
	int n = (int)p.size();
	int k = 0;
	if (n <= 2) {
		return p;
	}
	sort(p.begin(), p.end(), [&](point i, point j) { return (abs(i.x - j.x) < eps ? i.y < j.y : i.x < j.x); });
	p.resize(unique(p.begin(), p.end()) - p.begin());
	vector<point> res(2 * n);
	for (int i = 0; i < n; i++) { // lower_hull
		while (k > 1 && cross(res[k - 1] - res[k - 2], p[i] - res[k - 1]) <= (vertex_only ? eps : -eps)) {
			k--;
		}
		res[k++] = p[i];
	}
	for (int i = n - 2, t = k; i >= 0; i--) { // upper_hull
		while (k > t && cross(res[k - 1] - res[k - 2], p[i] - res[k - 1]) <= (vertex_only ? eps : -eps)) {
			k--;
		}
		res[k++] = p[i];
	}
	res.resize(k - 1);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<point> p(n);
	vector<long long> q(n);
	map<long long, long long> mp;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y >> q[i];
		long long c = p[i].x * (long long)1e9 + p[i].y;
		if (!mp.count(c)) {
			mp[c] = LLONG_MAX;
		}
		mp[c] = min(mp[c], q[i]);
	}
	auto c = p;
	c = convexhull(c);
	long long ans = 0;
	for (auto r : c) {
		ans += mp[r.x * (long long)1e9 + r.y];
	}
	cout << ans << '\n';
	return 0;
}
