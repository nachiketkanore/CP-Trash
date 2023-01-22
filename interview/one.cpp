#include <bits/stdc++.h>
using namespace std;

string magiclamp(vector<int> wish) {
	sort(wish.begin(), wish.end(), [&](int first, int second) {
		string A = to_string(first), B = to_string(second);
		return A + B > B + A;
	});
	string ans;
	for (int a : wish) {
		ans += to_string(a);
	}
	reverse(ans.begin(), ans.end());
	while ((int)ans.size() > 1 && ans.back() == '0') {
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	// vector<int> A{ 13, 65, 9, 20 };
	vector<int> A{ 0, 0, 0, 0 };
	cout << magiclamp(A);
	return 0;
}
