#include <stdio.h>

struct school {
	char* name;
	school(char* name_) {
		name = (char*)malloc(25 * sizeof(char));
		for (int i = 0; i < 25; i++) {
			name[i] = name_[i];
		}
	}
	school() {
		name = "PICT, Pune";
	}
};

void test() {
	char name[] = "nachiket";
	printf("%s", name);
}

int main() {
	test();
	// char *name = "nachiket";
	// printf("%s", name);
}
