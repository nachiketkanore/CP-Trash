#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int x;
	cin >> x;
}

int hello() {
	int main;
	cin >> main;
	cout << main << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	set<int> f(a.begin(), a.end());
	cout << (int)f.size() << '\n';
}
