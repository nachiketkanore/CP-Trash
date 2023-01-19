/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 19 August 2021 01:09:02 PM IST
 **/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int cnt1 = N, cnt2 = 1;
		int first = i, second = i + 1;
		if (i % 2 == 0) {
			swap(cnt1, cnt2);
			swap(first, second);
		}
		while (cnt1--)
			cout << first;
		while (cnt2--)
			cout << second;
		cout << '\n';
	}
}
