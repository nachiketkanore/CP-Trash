#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> go(int n) {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int &x : a) {
		int hello;
		cin >> hello;
        cin >> x;
        sum += x;
    }
    sort(a.begin(), a.end());
    return make_pair(sum, a);
}

int main() {
  int n, inversions = 0;
  cin >> n;
  int n;
  cin >> n;
  vector<int> a;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
        inversions++;
      }
    }
  }
  cout << inversions << '\n';
}
