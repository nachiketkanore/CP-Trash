#include <stdio.h>
#include <stdlib.h>

struct vector {
	int N;
	int* A;
	void push_back(int val) {
		printf("Push Back: %d\n", val);
	}
};

int main() {
}
