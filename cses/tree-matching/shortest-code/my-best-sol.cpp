#include "bits/stdc++.h"
using namespace std;
#define I int

set<I> g[200001];
I u, v, D[2][200001];

I G(I X, I P, I F) {
	I& A = D[F][X];
	if (~A)
		return A;
	I B = 0;
	for (I Y : g[X])
		B += Y ^ P ? G(Y, X, 0) : 0;
	A = B;

	for (I Y : g[X])
		Y ^ P&& !F ? A = max(A, 1 + G(Y, X, 1) + B - G(Y, X, 0)) : 0;

	return A;
}

I main() {
	memset(D, -1, sizeof(D));
	cin >> u;
	while (cin >> u >> v)
		g[u].insert(v), g[v].insert(u);
	cout << G(1, 1, 0);
}
