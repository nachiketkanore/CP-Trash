#include <bits/stdc++.h>
using namespace std;

// observations
// - for some subarray A
// if we have count of bits for all elements
// if all those counts are even
// then for that subarray it is possible to make all elements = 0
// for [3, 1, 2]
// count[0] = 2
// count[1] = 2
// count[2..] = 0
// how to do it better than O(N * N)
//
// wait: we can also keep subtracting 1 from pairs
// doing the following:
// A[i] -= 16, A[j] -= 16
// is same as
// A[i] -= 1, A[j] -= 1 --> 16 times --> is the same thing
// more observations
// [4, 16] -> not possible
// [1, 2, 3] -> possible
// [sorted subarray] -> [other, max]
// when other sum = max -> possible ?

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
