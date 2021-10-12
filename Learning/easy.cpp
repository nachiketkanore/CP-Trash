#include <iostream>
using namespace std;

void test_main() {
	string name;
	cin >> name;
}

void* get_pointer(int SIZE) {
	int* ret = new int[SIZE];
	return ret;
}

int solution(int N, int A[]) {
	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (A[i] < 0) A[i] = -1;
		if (A[i] > 0) A[i] = 1;
		ans *= A[i];
	}
	return ans;
}

string get_string(char *s) {
	string ret;
	int i = 0;
	while (s[i] != '\0') {
		ret += s[i];
		i++;
	}
	return ret;
}

int isSameReflection(char* word1, char* word2) {
	string S = get_string(word1);
	string T = get_string(word2);
	const int N = S.size(), M = T.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			string first = S.substr(i) + S.substr(0, i);
			string second = T.substr(j) + T.substr(0, j);
			if (first == second) return 1;
		}
	}
	return -1;
}

int main() {
	char one[200];
	char two[200];
	scanf("%s", one);
	scanf("%s", two);
	cout << isSameReflection(one, two);
}
