#include <bits/stdc++.h>
using namespace std;

int recurringString(int N, char* A[], char* B) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cout << A[i] << '\n';
        bool found = strcmp(A[i], B) == 0;
        cout << A[i] << ' ' << B << ' ' << found << '\n';
        int len = strlen(A[i]);
        for (int j = 0; j < len; j++) {
            char old = A[i][j];
            char nxt = old == 'Z' ? 'A' : old + 1;
            A[i][j] = nxt;
            found |= strcmp(A[i], B) == 0;
            A[i][j] = old;
        }
        ans += found;
    }
    return ans;
}

int main() {
    char*A[] = { (char*) "AAAA", (char*) "BAAA" };
    cout << A[0] << '\n';
    cout << recurringString(2, A, (char*) "BAAA") << endl;
}
