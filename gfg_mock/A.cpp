#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace NumberTheory {
const int N = 1e6;
const int MOD = 1e9 + 7;

int power(int a, int b, int mod) {
	assert(b >= 0);
	int ret = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			ret *= a;
		ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

int power(int a, int b) {
	assert(b >= 0);
	int ret = 1;
	while (b) {
		if (b & 1)
			ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

bool is_prime(int u) {
	if (u < 2)
		return false;
	for (int d = 2; d * d <= u; d++)
		if (u % d == 0)
			return false;
	return true;
}

vector<int> get_primes_upto(int n) {
	// returns all primes <= n
	vector<int> ret;
	for (int i = 1; i <= n; i++)
		if (is_prime(i))
			ret.push_back(i);
	return ret;
}

vector<bool> get_sieve_upto(int n) {
	// sieve <bool> array <= n
	vector<bool> ret(n + 1, true);
	ret[0] = ret[1] = false;
	for (int i = 2; i <= n; i++)
		if (ret[i])
			for (int j = i << 1; j <= n; j += i)
				ret[j] = false;
	return ret;
}
} // namespace NumberTheory

int main() {

	return 0;
}
