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

const int _ = 5e5 + 5, LOG = 21;
int Q, id_of[_], to[LOG][_];
vector<int> A;
vector<Query> queries;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
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
	memset(to, -1, sizeof(to));
	memset(id_of, -1, sizeof(id_of));
	int j = sz(queries) - 1;
	for (int i = sz(A) - 1; i >= 0; i--) {
		int len = i + 1;
		while (j >= 0 && queries[j].len >= len) {
			Query add = queries[j];
			int nxt_id = id_of[add.y];
			to[0][j] = nxt_id;
			for (int jump = 1; jump < LOG; jump++) {
				if (to[jump - 1][j] >= 0)
					to[jump][j] = to[jump - 1][to[jump - 1][j]];
			}
			id_of[add.x] = j;
			j--;
		}
		int curr_id = id_of[A[i]];
		if (curr_id < 0)
			continue;
		for (int jump = LOG - 1; jump >= 0; jump--) {
			if (to[jump][curr_id] >= 0) {
				curr_id = to[jump][curr_id];
			}
		}
		A[i] = queries[curr_id].y;
	}
	for (int x : A) {
		cout << x << " ";
	}
	return 0;
}
