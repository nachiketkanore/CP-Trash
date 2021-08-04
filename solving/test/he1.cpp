#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

int n, m, a[N], same_from[N];

class LinkedList {
	private:
		LinkedList* head;
		LinkedList* next;
	public:
		LinkedList(LinkedList* other) { 
			head = other;
		}

		int get_length() {
			int len = 0;
			LinkedList* curr = head;
			while (curr != NULL) {
				++len;
				curr = curr->next;
			}
		}

		void rotate_left(int times) {
			int len = this->get_length();
		}

};

int32_t main() {
	cin >> n >> m;
	FOR (i,1,n) cin >> a[i];
	same_from[n] = 1;
	for (int i = n-1; i >= 1; i--) {
		if (a[i] == a[i+1]) same_from[i] = same_from[i+1] + 1;
		else same_from[i] = 1;
	}
	FOR (i,1,m) {
		int L, R, val;
		cin >> L >> R >> val;
		if (a[L]^val) cout << L << '\n';
		else {
			int val_cnt = same_from[L];
			int len = R - L + 1;
			if (val_cnt >= len) cout << "-1\n";
			else cout << L + val_cnt << '\n';
		}
	}
}

