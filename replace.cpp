/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 15 May 2022 07:58:24 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct Query {
	int len, x, y;
	Query(int len, int x, int y) : len(len), x(x), y(y) {
	}
	friend ostream& operator<<(ostream& out, const Query& q) {
		out << "{ " << q.len << ", " << q.x << ", " << q.y << " }\n";
		return out;
	}
};

int Q;
vector<int> A;
vector<Query> queries;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// not optimal: will optimize later
	cin >> Q;
	while (Q--) {
		int type, x, y;
		cin >> type >> x;
		if (type == 1) {
			A.push_back(x);
		} else {
			cin >> y;
			queries.push_back(Query(sz(A), x, y));
		}
	}
	for (int i = sz(A) - 1; i >= 0; i--) {
		int len = i + 1;
		int val = A[i];
		int lo = 0, hi = sz(queries) - 1;
		int start = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (queries[mid].len >= len) {
				start = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		if (start == -1)
			continue;
		for (int id = start; id < sz(queries); id++) {
			Query q = queries[id];
			if (q.len < len)
				continue;
			if (q.x == val) {
				val = q.y;
			}
		}
		A[i] = val;
	}
	for (int x : A) {
		cout << x << " ";
	}
	return 0;
}
