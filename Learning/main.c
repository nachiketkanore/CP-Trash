#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* get_arr(int size) {
	int* ret = (int*) malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		ret[i] = i;
	}
	return ret;
}

void* test(int N) {
	return NULL;
}

int main() {
	int N = 20;
	int *arr = get_arr(N);
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
