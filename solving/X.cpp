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

namespace nachiket {
const int MAX_N = 100500;
int st[MAX_N << 2];
FOR(i, 1, )
} // namespace nachiket

const int inf = 1e18;
const int N = 5e5 + 5;

string my_strs = { "nachiket", "kanore", "anant", "hello", "world", "how", "are", "you", "nachiket", "kanore" }

class myException {
	public:
	int T;
	myException(int T) {
		this->T = T;
	}
};

int32_t main() {
	int T = 20;
	while (T--) {
		try {
			if (T == 2)
				throw myException(T);
		} catch (myException obj) {
			cerr << "Exception on T = " << obj.T << endl;
			return 0;
		}
		cerr << T << endl;
	}
}
