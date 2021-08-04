#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, sum = 0;
    cin >> n >> m; 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum % m << '\n';
}

int main() {
    vector<int> fact;
    for (int i = 0; i < 10000; i++) {
        if (fact.empty()) fact.push_back(1);
        else fact.push_back((i + 1) * fact.back());
    }
	cout << "NACHIKET\n";
}
