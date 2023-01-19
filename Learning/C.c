#include <stdbool.h>
#include <stdio.h>

void print(const char* s) {
	if (!s)
		return;
	int id = 0;
	while (s[id] != '\0') {
		printf("%c", s[id]);
		id++;
	}
	printf("\n");
}

char* test() {
	return "nachiket";
}

struct Human {
	char* attributes;
	int height, weight, age;
};

int main(void) {

	int var = 21;
	int nachiket = 0032;
	const char name[128] = "Nachiket Kanore";

	print(NULL);
	printf("%s\n", name);
	printf("%d\n", var);
	printf("%d\n", nachiket);

	return 0;
}
