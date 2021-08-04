#include <stdio.h>

#define N 100000

struct {
	struct node {
		int sum, mn, mx;
		node() {
			sum = 0;
			mn = 1e9;
			mx = -1e9;
		}
		node(int val) {
			sum = mn = mx = val;
		}
		node(int sum_, int mn_, int mx_) {
			sum = sum_;
			mn = mn_;
			mx = mx_;
		}
	};

}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", n);
}
