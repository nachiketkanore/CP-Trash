#include<stdio.h>

void test() {
	char* input;
	switch (input) {
		case (char *)"1":
			break;
		case (char *)"2";
			break;
	}
}


int countSubsets(int *a, int id, int remain) {
	if (remain < 0) return 0;
	if (remain == 0) return 1;
	if (id == 4) return 0;

	int take = countSubsets(a, id + 1, remain - a[id]);
	int dont_take = countSubsets(a, id + 1, remain);

	return take + dont_take;
}

int main(){
	int a[] = {1, 2, 3, 4};
	printf("%d", countSubsets(a, 0, 6));
	return 0;
	/* char a = 30, b = 5; */
	/* char *p = &a, *q = &b; */
	/* printf("%d\n", (int)(p - q)); */
	/* return 0; */
}

