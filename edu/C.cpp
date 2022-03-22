/**
 *    Author: Solve Machine
 *    Created: Tuesday 22 March 2022 08:03:26 PM IST
**/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

// struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int md = 1e9+7;
int B = 73; //Sheldon prime (lol)
const int mxN = 1e6+6;
int pB[mxN];
int N;
string S;

struct DS {
	vector<int> bit;
	int N;

	DS(int len) {
		N = len << 2;
		bit = vector<int> (N);
	}

    void update(int k, int x) {
        x %= md;
        if (x < md) x += md;
        for (; k < N; k += k&-k) {
            (bit[k] += x) %= md;
        }
    }

    int query(int k) {
        int s = 0;
        for (; k > 0; k -= k&-k)
            (s += bit[k]) %= md;
        return s;
    }
};


template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

void solve() {
	cin >> N >> S;
	DS pre(N), suf(N);
	for (int i = 0; i < N; i++) {
        pre.update(i+1, (S[i]-'a'+1) * pB[i]);
        suf.update(i+1, (S[i]-'a'+1) * pB[N-i-1]);
	}
	auto check_pal = [&](int x, int y) {
		if (y - x + 1 <= 1) return false;
		int h1 = (pre.query((x+y)/2) - pre.query(x-1) + md) % md;
		int m1 = pB[x-1];
		int h2 = (suf.query(y) - suf.query((x+y-1)/2) + md) % md;
		int m2 = pB[N-y];
		return (h1 * m2 % md == h2 * m1 % md ? true: false);
	};

	int ans = 0, i = 0;
	int rem = 0;
	for (; i < N; i++) {
		int j = i + 1;
		int sum = S[i] == '(' ? +1: -1;
		bool neg = sum < 0;
		for (; j < N; j++) {
			sum += S[j] == '(' ? +1: -1;
			neg |= sum < 0;
			if (!neg && sum == 0) {
				++ans;
				// see(i, j, "regular");
				break;
			}
			if (check_pal(i + 1, j + 1)) {
				// see(i, j, "palindrome");
				++ans;
				break;
			}
		}
		if (j == N) {
			rem = N - i;
		}
		// see(i, j);
		i = j;
	}

	cout << ans << ' ' << rem << '\n';
}

int32_t main() {
    pB[0] = 1;
    for (int i = 1; i < mxN; i++)
        pB[i] = pB[i-1] * B % md;
	int T; cin >> T;
	while (T--) {
		solve();
	}
}
