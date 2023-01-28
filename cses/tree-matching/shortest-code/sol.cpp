#include <bits/stdc++.h>
using namespace std;
#define i int

set<i> g[200005];
i a, b, s[200005];

i d(i c, i p) {
	i r = 0;
	for (i a : g[c])
		r += a ^ p ? d(a, c) : 0;

	if (!s[c] & !s[p])
		r++, s[c] = s[p] = 1;

	return r;
}

i main() {
	for (cin >> a; cin >> a >> b;)
		g[a].insert(b), g[b].insert(a);

	s[0] = 1;
	cout << d(1, 0);
}
