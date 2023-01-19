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
		int n;
		cin >> n;
		auto get_xor = [&](int upto) {
			int mod = upto % 4;
			if (mod == 0)
				return upto;
			if (mod == 1)
				return int(1);
			if (mod == 2)
				return upto + 1;
			return int(0);
		};
		vector<int> ans;
		for (int i = n; i >= 1; i--) {
			if (get_xor(i) == 0)
				break;
			ans.push_back(i);
		}
		cout << sz(ans) << ' ';
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
	}
}
