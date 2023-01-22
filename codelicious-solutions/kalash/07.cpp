/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

/*/---------------------------IO(Debugging)----------------------/*/

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
istream& operator>>(istream& is, T_container& v) {
	for (T& x : v)
		is >> x;
	return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator<<(ostream& os, __int128 const& value) {
	static char buffer[64];
	int index = 0;
	__uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
	if (value < 0)
		os << '-';
	else if (T == 0)
		return os << '0';
	for (; T > 0; ++index) {
		buffer[index] = static_cast<char>('0' + (T % 10));
		T /= 10;
	}
	while (index > 0)
		os << buffer[--index];
	return os;
}
istream& operator>>(istream& is, __int128& T) {
	static char buffer[64];
	is >> buffer;
	size_t len = strlen(buffer), index = 0;
	T = 0;
	int mul = 1;
	if (buffer[index] == '-')
		++index, mul *= -1;
	for (; index < len; ++index)
		T = T * 10 + static_cast<int>(buffer[index] - '0');
	T *= mul;
	return is;
}
#endif

template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
	os << '{';
	string sep;
	for (const T& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <class P, class Q = vector<P>, class R = less<P>> ostream& operator<<(ostream& out, priority_queue<P, Q, R> const& M) {
	static priority_queue<P, Q, R> U;
	U = M;
	out << "{ ";
	while (!U.empty())
		out << U.top() << " ", U.pop();
	return (out << "}");
}
template <class P> ostream& operator<<(ostream& out, queue<P> const& M) {
	static queue<P> U;
	U = M;
	out << "{";
	string sep;
	while (!U.empty()) {
		out << sep << U.front();
		sep = ", ";
		U.pop();
	}
	return (out << "}");
}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args) {
	int count_open = 0, len = 1;
	for (int k = 1;; ++k) {
		char cur = *(names + k);
		count_open += (cur == '(' ? 1 : (cur == ')' ? -1 : 0));
		if (cur == ',' && count_open == 0) {
			const char* comma = names + k;
			cerr.write(names, len) << " : " << arg1 << " | ";
			__f(comma + 1, args...);
			return;
		}
		len = (cur == ' ' ? len : k + 1);
	}
}
#else
#define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN, long long r = LLONG_MAX) {
	uniform_int_distribution<int64_t> generator(l, r);
	return generator(rng);
}
struct custom_hash {						 // Credits: https://codeforces.com/blog/entry/62393
	static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	template <typename L, typename R> size_t operator()(pair<L, R> const& Y) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
	}
};

/*/---------------------------Defines----------------------/*/
#define endl "\n"
#define all(v) (v).begin(), (v).end()

namespace Geometry {
template <typename T> inline typename enable_if<!is_floating_point<T>::value, bool>::type less_compare(const T& a, const T& b) {
	return a < b;
}
template <typename T> inline typename enable_if<!is_floating_point<T>::value, bool>::type equal_compare(const T& a, const T& b) {
	return a == b;
}
template <typename T> inline typename enable_if<!is_floating_point<T>::value, bool>::type greater_compare(const T& a, const T& b) {
	return a > b;
}

constexpr long double __eps = 1e-10;
constexpr long double __INF = 1e100;
constexpr long double __PI = acosl(-1.0);

template <typename T> inline typename enable_if<is_floating_point<T>::value, bool>::type less_compare(const T& a, const T& b) {
	return a + __eps < b;
}
template <typename T> inline typename enable_if<is_floating_point<T>::value, bool>::type equal_compare(const T& a, const T& b) {
	return fabs(a - b) < __eps;
}
template <typename T> inline typename enable_if<is_floating_point<T>::value, bool>::type greater_compare(const T& a, const T& b) {
	return a > b + __eps;
}

template <typename T> inline constexpr T numeric_max() {
	return numeric_limits<T>::max();
}

#ifdef __SIZEOF_INT128__
template <> inline constexpr __uint128_t numeric_max() {
	return __uint128_t(-1);
}
template <> inline constexpr __int128_t numeric_max() {
	return (__uint128_t(-1) >> 1);
}
#endif

template <typename T> inline constexpr typename enable_if<!is_floating_point<T>::value, T>::type numeric_inf() {
	return numeric_max<T>();
}
template <typename T> inline constexpr typename enable_if<is_floating_point<T>::value, T>::type numeric_inf() {
	return static_cast<T>(__INF);
}

template <typename T> struct point {
	public:
	T x, y;
	point(T _x = T{}, T _y = T{}) : x(_x), y(_y) {
	}
	point(const initializer_list<T>& _a) : x(*_a.begin()), y(*(_a.begin() + 1)) {
		assert(_a.size() == 2);
	}

	template <typename U> explicit operator point<U>() const {
		return point<U>(static_cast<U>(x), static_cast<U>(y));
	}
	void swap(point& other) {
		std::swap(x, other.x);
		std::swap(y, other.y);
	}
	point& operator+=(const point& p) {
		x += p.x;
		y += p.y;
		return *this;
	}
	point& operator-=(const point& p) {
		x -= p.x;
		y -= p.y;
		return *this;
	}
	point operator+(const point& p) const {
		return point(x + p.x, y + p.y);
	}
	point operator-(const point& p) const {
		return point(x - p.x, y - p.y);
	}
	template <typename U> point operator*(const U& c) const {
		return point(x * c, y * c);
	}
	template <typename U> friend point operator*(const U& c, const point<T>& p) {
		return point(p.x * c, p.y * c);
	}
	template <typename U> point& operator*=(const U& c) {
		x *= c;
		y *= c;
		return *this;
	}
	template <typename U> point operator/(const U& c) const {
		return point(x / c, y / c);
	}
	template <typename U> point& operator/=(const U& c) {
		x /= c;
		y /= c;
		return *this;
	}
	point rotateCCW90() const {
		return point(-y, x);
	}
	point rotateCW90() const {
		return point(y, -x);
	}
	point reflect(const point<T>& origin) const {
		return 2 * origin - (*this);
	}
	template <typename U, typename Q> point<U> rotateCCW(const Q& _angle) {
		Q cosine = cos(_angle), sine = sin(_angle);
		return point<U>(static_cast<U>(x * cosine - y * sine), static_cast<U>(x * sine + y * cosine));
	}
	template <typename U> inline typename enable_if<is_floating_point<U>::value, U>::type norm() const {
		return sqrtl(static_cast<U>(x) * static_cast<U>(x) + static_cast<U>(y) * static_cast<U>(y));
	}
	template <typename U> inline U abs() const {
		return (static_cast<U>(x) * static_cast<U>(x) + static_cast<U>(y) * static_cast<U>(y));
	}
	template <typename U> inline U dist2(const point& p) const {
		return (static_cast<U>(p.x - x) * static_cast<U>(p.x - x) + static_cast<U>(p.y - y) * static_cast<U>(p.y - y));
	}
	template <typename U> inline U dist(const point& p) const {
		return sqrtl(this->dist2<U>(p));
	}
	template <typename U> inline U dot(const point& p) const {
		return static_cast<U>(x) * static_cast<U>(p.x) + static_cast<U>(y) * static_cast<U>(p.y);
	}
	template <typename U> inline U cross(const point<T>& p) const {
		return static_cast<U>(x) * static_cast<U>(p.y) - static_cast<U>(p.x) * static_cast<U>(y);
	}
	inline bool operator<(const point& p) const {
		return less_compare<T>(x, p.x) || (equal_compare<T>(x, p.x) && less_compare<T>(y, p.y));
	}
	inline bool operator==(const point& p) const {
		return equal_compare<T>(x, p.x) && equal_compare<T>(y, p.y);
	}
	inline bool operator!=(const point& p) const {
		return !equal_compare<T>(x, p.x) || !equal_compare<T>(y, p.y);
	}
	inline bool operator>(const point& p) const {
		return greater_compare<T>(x, p.x) || (equal_compare<T>(x, p.x) && greater_compare<T>(y, p.y));
	}
	inline bool operator<=(const point& p) const {
		return !(*this > p);
	}
	inline bool operator>=(const point& p) const {
		return !(*this < p);
	}
	friend istream& operator>>(istream& is, point& p) {
		return is >> p.x >> p.y;
	}
	friend ostream& operator<<(ostream& os, const point& p) {
		return os << "(" << p.x << ", " << p.y << ")";
	}

	template <typename U = long double> inline U polar_angle() const { // Not using epsilon for comparison here.
		return (y == 0 && x == 0) ? 0 : atan2l(y, x) + (y < 0 ? 2 * __PI : 0);
	}
};

// returns 1 if p to q is counterclock wise (wrt origin). 0 if collinear, -1 otherwise.
template <typename U> inline typename enable_if<is_floating_point<U>::value, int32_t>::type ccw(const point<U>& p, const point<U>& q) {
	U cross_prod = p.template cross<U>(q);
	return less_compare<U>(cross_prod, 0) ? -1 : (equal_compare<U>(cross_prod, 0) ? 0 : 1);
}
inline int32_t ccw(const point<int32_t>& p, const point<int32_t>& q) {
	int64_t cross_prod = p.template cross<int64_t>(q);
	return (cross_prod < 0 ? -1 : (cross_prod == 0 ? 0 : 1));
}
inline int32_t ccw(const point<int64_t>& p, const point<int64_t>& q) {
#ifdef __SIZEOF_INT128__
	__int128_t _cross_prod = p.template cross<__int128_t>(q);
	return (_cross_prod < 0 ? -1 : (_cross_prod == 0 ? 0 : 1));
#else
	long double double_value = p.x * (long double)q.y - q.x * (long double)p.y;
	if (abs(double_value) > 1e18) {
		return double_value > 0 ? 1 : -1;
	}
	uint64_t uint64_value = p.x * (uint64_t)q.y - q.x * (uint64_t)p.y;
	if (uint64_value == 0)
		return 0;
	return uint64_value >> 63 ? -1 : 1;
#endif
}
template <typename U> inline int32_t ccw(const point<U>& p, const point<U>& q, const point<U>& origin) {
	return ccw(p - origin, q - origin);
}

template <int TYPE> struct EndpointChecker {};
template <> struct EndpointChecker<0> { // no endpoint (ray)
	template <class F> bool operator()(const F& a, const F& b) const {
		return true;
	}
};
template <> struct EndpointChecker<1> { // closed endpoint
	template <class F> bool operator()(const F& a, const F& b) const {
		return !greater_compare<F>(b, a);
	}
};
template <> struct EndpointChecker<2> { // open endpoint
	template <class F> bool operator()(const F& a, const F& b) const {
		return less_compare<F>(a, b);
	}
};
template <typename T> struct Line {
	point<T> a, ab;

	Line() : a(), ab() {
	}
	Line(const point<T>& a, const point<T>& b, bool twoPoints = true) : a(a), ab(twoPoints ? b - a : b) {
	}
	Line(const T& _a, const T& _b, const T& _c) : ab(_b, -_a) { // ax + by + c = 0.
		assert(!equal_compare<T>(_a, 0) || !equal_compare<T>(_b, 0));
		a = (!equal_compare<T>(_a, 0) ? point<T>(-_c / _a, 0) : point<T>(0, -_c / _b));
	}
	template <typename U> explicit operator Line<U>() const {
		return Line<U>(static_cast<point<U>>(a), static_cast<point<U>>(ab), false);
	}

	template <typename U> inline array<U, 3> equation() const { // ax + by + c = 0.
		U _a = ab.y, _b = -ab.x;
		U _c = -(_a * static_cast<U>(a.x) + _b * static_cast<U>(a.y));
		return { _a, _b, _c };
	}
	inline point<T> b() const {
		return a + ab;
	}
	inline operator bool() const {
		return ab != point<T>();
	}
	inline bool onLine(const point<T>& q) const {
		if (ab == point<T>()) {
			return q == a;
		}
		return ccw(q - a, ab) == 0;
	}
	inline bool onSegment(const point<T>& q) const {
		return onLine(q) && q >= min(a, a + ab) && q <= max(a, a + ab);
	}
	inline bool onRay(const point<T>& q) const {
		return onLine(q) && !((q < a && point<T>() <= ab) || (q > a && point<T>() >= ab));
	}

	template <typename U> inline U distLine2(const point<T>& q) const {
		if (ab == point<T>()) {
			return q.template dist2<U>(a);
		}
		U z = (q - a).template cross<U>(ab);
		return (z * z) / ab.template abs<U>();
	}
	template <typename U> inline U distLine(const point<T>& q) const {
		if (ab == point<T>()) {
			return q.template dist<U>(a);
		}
		return abs(((q - a).template cross<U>(ab))) / (ab.template norm<U>());
	}

	template <typename U> inline U distRay2(const point<T>& q) const {
		if (ab == point<T>() || !greater_compare<U>((q - a).template dot<U>(ab), 0)) {
			return q.template dist2<U>(a);
		}
		U z = (q - a).template cross<U>(ab);
		return (z * z) / ab.template abs<U>();
	}
	template <typename U> inline U distRay(const point<T>& q) const {
		if (ab == point<T>() || !greater_compare<U>((q - a).template dot<U>(ab), 0)) {
			return q.template dist<U>(a);
		}
		return abs(((q - a).template cross<U>(ab))) / (ab.template norm<U>());
	}

	template <typename U> inline U distSegment2(const point<T>& q) const {
		if (ab == point<T>() || !greater_compare<U>((q - a).template dot<U>(ab), 0)) {
			return q.template dist2<U>(a);
		}
		if (!greater_compare<U>((ab + a - q).template dot<U>(ab), 0)) {
			return q.template dist2<U>(a + ab);
		}
		U z = (q - a).template cross<U>(ab);
		return (z * z) / ab.template abs<U>();
	}
	template <typename U> inline U distSegment(const point<T>& q) const {
		if (ab == point<T>() || !greater_compare<U>((q - a).template dot<U>(ab), 0)) {
			return q.template dist<U>(a);
		}
		if (!greater_compare<U>((ab + a - q).template dot<U>(ab), 0)) {
			return q.template dist<U>(a + ab);
		}
		return abs(((q - a).template cross<U>(ab))) / (ab.template norm<U>());
	}
	template <typename U> inline point<U> projectOnLine(const point<T>& q) const {
		point<U> ans = static_cast<point<U>>(a);
		if (ab != point<T>()) {
			ans += static_cast<point<U>>(ab) * (((q - a).template dot<U>(ab)) / (ab.template abs<U>()));
		}
		return ans;
	}
	template <typename U> inline point<U> projectOnSegment(const point<T>& q) const {
		point<U> ans = projectOnLine<U>(q);
		if (ans <= static_cast<point<U>>(min(a, a + ab))) {
			return static_cast<point<U>>(min(a, a + ab));
		} else if (ans >= static_cast<point<U>>(max(a, a + ab))) {
			return static_cast<point<U>>(max(a, a + ab));
		}
		return ans;
	}
	template <typename U> inline point<U> projectOnRay(const point<T>& q) const {
		point<U> ans = projectOnLine<U>(q);
		if ((ans < point<U>(a) && point<T>() <= ab) || (ans > point<U>(a) && point<T>() >= ab)) {
			return static_cast<point<U>>(a);
		}
		return ans;
	}

	inline bool isParallel(const Line<T>& q) const { // doesn't check for null lines!! what should be the correct thing??
		assert(ab != point<T>() && q.ab != point<T>());
		return ccw(ab, q.ab) == 0;
	}

	// Returned line intersection never of the form (0, 1) or (0, 2) or (2, 1)
	// inline with ray guidelines. Lot of work -- should likely be slow -- when
	// collinear lines. Write custom code for collinear if TLE? -- less generic.
	// UNTESTED!! -- non-collinear copied; should be correct.
	template <int LA, int LB, int RA, int RB, typename Q> inline pair<bool, Line<Q>> intersection(const Line<T>& q) const {
		assert(ab != point<T>() && q.ab != point<T>());
		Q value = ab.template cross<Q>(q.ab);
		if (equal_compare<Q>(value, 0)) {
			if (!onLine(q.a)) {
				return make_pair(false, Line<Q>{});
			}
			if (LA == 0 && LB == 0) {
				if ((RA == 0 && RB >= 1) || (RA == 2 && RB == 1)) {
					return make_pair(true, Line<Q>(q.a + q.ab, -q.ab));
				}
				return make_pair(true, Line<Q>(q));
			}
			if (RA == 0 && RB == 0) {
				if ((LA == 0 && LB >= 1) || (LA == 2 && LB == 1)) {
					return make_pair(true, Line<Q>(a + ab, -ab));
				}
				return make_pair(true, Line<Q>(a, ab));
			}

			point<T> lhs_a = a, lhs_b = a + ab;
			point<T> rhs_a = q.a, rhs_b = q.a + q.ab;

			int la = LA, lb = LB, ra = RA, rb = RB;
			if (lhs_a > lhs_b) {
				swap(lhs_a, lhs_b);
				swap(la, lb);
			}
			if (rhs_a > rhs_b) {
				swap(rhs_a, rhs_b);
				swap(ra, rb);
			}

			point<T> A, B;
			int a_idx, b_idx;

			if (la == 0 && ra == 0) {
				A = min(lhs_a, rhs_a);
				a_idx = 0;
			} else if (la == 0) {
				A = rhs_a;
				a_idx = ra;
			} else if (ra == 0) {
				A = lhs_a;
				a_idx = la;
			} else {
				A = max(lhs_a, rhs_a);
				a_idx = max((A == lhs_a ? la : 0), (A == rhs_a ? ra : 0));
			}

			if (lb == 0 && rb == 0) {
				B = max(lhs_b, rhs_b);
				b_idx = 0;
			} else if (lb == 0) {
				B = rhs_b;
				b_idx = rb;
			} else if (rb == 0) {
				B = lhs_b;
				b_idx = lb;
			} else {
				B = min(lhs_b, rhs_b);
				b_idx = max((B == rhs_b ? rb : 0), (B == lhs_b ? lb : 0));
			}
			if (B < A) {
				return make_pair(false, Line<Q>());
			}
			assert(a_idx + b_idx > 0);
			if (b_idx == 0 || (a_idx == 2 && b_idx == 1)) {
				return make_pair(false, Line<Q>(B, A, true));
			}
			return make_pair(false, Line<Q>(A, B, true));
		}

		Q ls = (q.a - a) ^ q.ab;
		Q rs = (q.a - a) ^ ab;
		if (less_compare<Q>(value, 0)) {
			value = -value, ls = -ls, rs = -rs;
		}
		bool intersect = EndpointChecker<LA>()(static_cast<Q>(0), 0) && EndpointChecker<LB>()(ls, value) &&
		EndpointChecker<RA>()(static_cast<Q>(0), rs) && EndpointChecker<RB>()(rs, value);

		if (intersect) {
			return make_pair(true, Line<Q>(a + ab * ls / value, Line<Q>()));
		}
		return make_pair(false, Line<Q>{});
	}

	template <typename Q> inline pair<bool, Line<Q>> LineIntersectLine(const Line<T>& q) const {
		return intersection<0, 0, 0, 0, Q>(q);
	}
	template <typename Q> inline pair<bool, Line<Q>> LineIntersectRay(const Line<T>& q) const {
		return intersection<0, 0, 1, 0, Q>(q);
	}
	template <typename Q> inline pair<bool, Line<Q>> LineIntersectSegment(const Line<T>& q) const {
		return intersection<0, 0, 1, 1, Q>(q);
	}

	template <typename Q> inline pair<bool, Line<Q>> RayIntersectLine(const Line<T>& q) const {
		return intersection<1, 0, 0, 0, Q>(q);
	}
	template <typename Q> inline pair<bool, Line<Q>> RayIntersectRay(const Line<T>& q) const {
		return intersection<1, 0, 1, 0, Q>(q);
	}

	template <typename Q> inline pair<bool, Line<Q>> RayIntersectSegment(const Line<T>& q) const {
		return intersection<1, 0, 1, 1, Q>(q);
	}

	template <typename Q> inline pair<bool, Line<Q>> SegmentIntersectLine(const Line<T>& q) const {
		return intersection<1, 1, 0, 0, Q>(q);
	}
	template <typename Q> inline pair<bool, Line<Q>> SegmentIntersectRay(const Line<T>& q) const {
		return intersection<1, 1, 1, 0, Q>(q);
	}
	template <typename Q> inline pair<bool, Line<Q>> SegmentIntersectSegment(const Line<T>& q) const {
		return intersection<1, 1, 1, 1, Q>(q);
	}
};

template <typename T> struct Polygon {
	public:
	vector<point<T>> a;
	Polygon(const vector<point<T>>& _a) : a(_a) {
	}
	Polygon(int n = 0) : a(n) {
	}
	Polygon(const initializer_list<point<T>>& _a) : a(_a) {
	}

	inline size_t size() const {
		return a.size();
	}
	inline auto begin() const {
		return a.begin();
	}
	inline auto end() const {
		return a.end();
	}

	point<T>& operator[](int x) {
		return a[x];
	}
	const point<T>& operator[](int x) const {
		return a[x];
	}
	// For point inside, (simple poly): returns > 0 for ccw, INT_MAX for on polygon
	int winding_number(const point<T>& q) const { // https://acm.timus.ru/problem.aspx?space=1&num=1599
		int n = static_cast<int>(a.size()), windingNumber = 0;

		for (int i = 0; i < n; ++i) {
			if (q == a[i]) {
				return INT_MAX;
			}
			int j = (i + 1 == n ? 0 : i + 1);
			if (equal_compare(a[i].y, q.y) && equal_compare(a[j].y, q.y)) {
				if (!greater_compare(min(a[i].x, a[j].x), q.x) && !less_compare(max(a[i].x, a[j].x), q.x)) {
					return INT_MAX;
				}
			} else {
				bool below = less_compare(a[i].y, q.y);
				if (below != less_compare(a[j].y, q.y)) {
					int orientation = ccw(q, a[j], a[i]);
					if (orientation == 0)
						return INT_MAX;
					if (below == (orientation > 0))
						windingNumber += below ? -1 : 1;
				}
			}
		}
		return windingNumber;
	}
	int PointInPolygon(const point<T>& q) const {
		int z = winding_number(q);
		return (z == INT_MAX ? 0 : (z == 0 ? 1 : -1));
	}

	friend istream& operator>>(istream& is, Polygon& p) {
		return is >> p.a;
	}
	friend ostream& operator<<(ostream& os, const Polygon& p) {
		return os << p.a;
	}

	template <typename U> U doubled_signed_area() const {
		U ans = 0;
		const int n = static_cast<int>(a.size());
		for (int i = 0; i < n; ++i) {
			int j = (i == n - 1 ? 0 : i + 1);
			ans += a[i].template cross<U>(a[j]);
		}
		return ans;
	}

	template <typename U> inline U signed_area() const {
		return doubled_signed_area<U>() / 2;
	}

	template <typename U> inline U doubled_area() const {
		U ans = doubled_signed_area<U>();
		return (ans < 0 ? -ans : ans);
	}

	template <typename U> inline U area() const {
		return doubled_area<U>() / 2;
	}

	template <typename U> inline point<U> centroid() const {
		const int n = static_cast<int>(a.size());
		U scale = doubled_signed_area<U>() * 3;
		if (equal_compare<U>(scale, 0)) {
			return point<U>(numeric_inf<U>(), numeric_inf<U>());
		}
		point<U> ans(0, 0);
		for (int i = 0; i < n; ++i) {
			int j = (i == n - 1 ? 0 : i + 1);
			ans += static_cast<point<U>>((a[i] + a[j])) * (a[i].template cross<U>(a[j]));
		}
		return ans / scale;
	}

	// True if orientation of a simple polygon is counter-clockwise or n <= 2.
	bool is_ccw() const {
		int n = static_cast<int>(a.size());
		int i = static_cast<int>(min_element(a.begin(), a.end()) - a.begin());
		int orient = ccw(a[(i == 0 ? n - 1 : i - 1)], a[(i + 1 == n ? 0 : i + 1)], a[i]);
		assert(n <= 2 || orient != 0);
		return (n <= 2 || orient < 0);
	}
};

template <typename T> struct ConvexPolygon : public Polygon<T> {
	private:
	inline void setup(bool is_sorted) {
		const int n = this->a.size();
		if (n <= 1) {
			top = 0;
			return;
		}

		if (!is_sorted) {
			sort(this->a.begin(), this->a.end());
		}
		vector<point<T>> hull;
		hull.reserve(n);

		for (int phase = 0; phase < 2; ++phase) {
			size_t original = hull.size();
			for (const auto& pt : this->a) {
				while (hull.size() >= original + 2 && ccw(hull[hull.size() - 2], hull.back(), pt) <= 0)
					hull.pop_back();
				hull.push_back(pt);
			}
			assert(hull.size() >= original + 2);
			if (phase == 0) {
				top = static_cast<int>(hull.size()) - 1;
				reverse(this->a.begin(), this->a.end());
			}
			hull.pop_back();
		}
		if (hull[0] == hull.back()) {
			assert(hull.size() == 2);
			hull.pop_back();
			top = 0;
		}
		assert(hull[top] == *max_element(hull.begin(), hull.end()));
		swap(this->a, hull);
	}

	public:
	int top;

	ConvexPolygon(const vector<point<T>>& _a, const bool is_sorted = false) : Polygon<T>(_a) {
		setup(is_sorted);
	}
	ConvexPolygon(int n = 0) : Polygon<T>(n) {
	}
	ConvexPolygon(const initializer_list<point<T>>& _a, const bool is_sorted = false) : Polygon<T>(_a) {
		setup(is_sorted);
	}
	ConvexPolygon(const Polygon<T>& _a, const bool is_sorted = false) : Polygon<T>(_a) {
		setup(is_sorted);
	}

	// //1 for outside and 0 for on/ -1 inside
	int PointInPolygon(const point<T>& point) { // Tested: https://codeforces.com/contest/166/problem/B
		if (point < this->a[0] || point > this->a[top])
			return 1;
		int orient = ccw(point, this->a[top], this->a[0]);
		if (orient == 0) {
			if (point == this->a[top] || point == this->a[0]) {
				return 0;
			}
			return (top <= 1 || (top + 1 == this->a.size())) ? 0 : -1;
		} else if (orient > 0) { // below a[0] --- a[top].
			auto itDown = lower_bound(this->a.begin() + 1, this->a.begin() + top, point);
			return ccw(point, itDown[0], itDown[-1]);
		} else {
			auto itUp = upper_bound(this->a.rbegin(), this->a.rend() - top - 1, point);
			return ccw(itUp[0], point, (itUp == this->a.rbegin() ? this->a[0] : itUp[-1]));
		}
	}

	template <typename U> pair<pair<point<T>, point<T>>, U> diameter() const { // UNTESTED
		const int n = static_cast<int>(this->a.size());
		U best = 0;
		point<T> x = this->a[0], y = this->a[0];
		for (int i = 0, j = (n < 2 ? 0 : 1); i < j; ++i) {
			while (true) {
				U cur = this->a[i].template dist2<U>(this->a[j]);
				if (best < cur) {
					best = cur;
					x = this->a[i];
					y = this->a[j];
				}
				int nx_j = (j + 1 == n ? 0 : j + 1);
				if (ccw(this->a[i + 1] - this->a[i], this->a[nx_j] - this->a[j]) <= 0)
					break;
				j = nx_j;
			}
		}
		return { { x, y }, best };
	}

	friend istream& operator>>(istream& is, ConvexPolygon& p) {
		is >> p.a;
		p.setup(false);
		return is;
	}

	inline bool is_simple() const {
		return true;
	}
	inline bool is_ccw() const {
		return (this->a.size() <= 2 || ccw(this->a[0], this->a[2], this->a[1]) < 0);
	}

	vector<point<T>> minkowski_sum_vec(const vector<point<T>>& other) const {
		int i = 0, j = 0;
		const int n = this->size(), m = other.size();
		vector<point<T>> ans;
		ans.reserve(n + m);
		int crossed = 0;
		while (crossed < 2) {
			ans.push_back(this->a[i] + other[j]);
			int next_i = (i + 1 == n ? 0 : i + 1), next_j = (j + 1 == m ? 0 : j + 1);
			int orient = ccw(this->a[next_i] - this->a[i], other[next_j] - other[j]);
			if (orient >= 0) {
				crossed += (next_i < i);
				i = next_i;
			}
			if (orient <= 0) {
				crossed += (next_j < j);
				j = next_j;
			}
		}
		return ans;
	}
	inline ConvexPolygon<T> minkowski_sum(const ConvexPolygon<T>& other) const {
		ConvexPolygon<T> final;
		final.a = minkowski_sum_vec(other.a);
		final.top = static_cast<int>(max_element(final.a.begin(), final.a.end()) - final.a.begin());
		return final;
	}

	template <typename U> U minimum_dot(const T& x) const {
		point<T> cur(x, 1);
		int lo = 0, hi = top;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (less_compare(this->a[mid].template dot<U>(cur), this->a[mid + 1].template dot<U>(cur))) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return this->a[lo].template dot<U>(cur);
	}

	template <typename U> U maximum_dot(const T& x) const {
		point<T> cur(x, 1);
		int lo = top, hi = static_cast<int>(this->a.size()) - 1;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (greater_compare(this->a[mid].template dot<U>(cur), this->a[mid + 1].template dot<U>(cur))) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return max(this->a[lo].template dot<U>(cur), this->a[0].template dot<U>(cur));
	}
};
}; // namespace Geometry
using namespace Geometry;
/*/-----------------------------Code begins----------------------------------/*/

void solve() {
	int n;

	cin >> n;

	vector<array<int, 3>> a(n);
	cin >> a;

	map<array<int, 2>, int> q;

	for (auto& [x, y, z] : a) {
		if (q.find({ x, y }) != q.end()) {
			q[{ x, y }] = min(q[{ x, y }], z);
		} else {
			q[{ x, y }] = z;
		}
	}

	vector<point<int>> r;

	for (auto& e : q) {
		r.push_back({ e.first[0], e.first[1] });
	}
	long long ans = 0;

	auto R = ConvexPolygon(r);

	for (auto pts : R) {
		ans += q[{ pts.x, pts.y }];
	}

	cout << ans << endl;
}

int main() {
	// Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with
	// unordered set Or use gp_hash_table<X,null_type>
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed << setprecision(25);
	cerr << fixed << setprecision(10);
	auto start = std::chrono::high_resolution_clock::now();

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	// cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
}
