#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		const int n = s.size();
		string t;
		for (char ch : s) {
			if (t.empty())
				t += ch;
			else if (t.back() == '1' && ch == '0')
				t.pop_back();
			else
				t += ch;
		}
		s = t;
		t.clear();
		for (char ch : s) {
			if (t.empty())
				t += ch;
			else if (t.back() == '0' && ch == '0')
				t.pop_back();
			else
				t += ch;
		}
		cout << sz(t) << '\n';
	}
}
