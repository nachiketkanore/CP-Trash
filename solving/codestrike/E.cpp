#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int N = 40, mod = 1e9 + 7, inf = 1e12;

string A, B;
int n, dp[N][2][2][2];
int have;

int go(int pos, bool bigA, bool smallB, bool start) {
	if (pos >= n)
		return 1;

	int& ans = dp[pos][bigA][smallB][start];
	if (~ans)
		return ans;
	ans = 0;
	for (int i = 0; i < 10; i++)
		if ((have >> i & 1) || (i == 0 && !start)) {
			if (!bigA && i < A[pos] - '0')
				continue;
			if (!smallB && i > B[pos] - '0')
				continue;

			ans += go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), start || i > 0);
			if (ans > inf)
				break;
		}
	return ans;
}

int cnt_range(string two) {
	memset(dp, -1, sizeof(dp));
	A = "1";
	B = two;
	reverse(A.begin(), A.end());
	while (sz(A) < sz(B))
		A.push_back('0');
	reverse(A.begin(), A.end());
	n = sz(B);
	int ans = 0;

	for (int i = 0; i < 10; i++)
		if ((have >> i & 1) || i == 0) {
			if (i < A[0] - '0')
				continue;
			if (i > B[0] - '0')
				continue;

			ans += go(1, i > A[0] - '0', i<B[0] - '0', i> 0);
			if (ans > inf)
				break;
		}
	return ans;
}

string sum(string str1, string str2) {
	if (str1.length() > str2.length())
		swap(str1, str2);
	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++) {
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = n1; i < n2; i++) {
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry)
		str.push_back(carry + '0');

	reverse(str.begin(), str.end());

	return str;
}

string divide(string number, int divisor) {
	string ans;
	int idx = 0;
	int temp = number[idx] - '0';
	while (temp < divisor)
		temp = temp * 10 + (number[++idx] - '0');

	while (number.size() > idx) {
		ans += (temp / divisor) + '0';
		temp = (temp % divisor) * 10 + number[++idx] - '0';
	}

	if (ans.length() == 0)
		return "0";

	return ans;
}

bool isSmaller(string str1, string str2) {
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
		return true;
	if (n2 < n1)
		return false;

	for (int i = 0; i < n1; i++)
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;

	return false;
}

string subtract(string str1, string str2) {
	if (isSmaller(str1, str2))
		swap(str1, str2);

	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for (int i = 0; i < n2; i++) {

		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		} else
			carry = 0;

		str.push_back(sub + '0');
	}

	for (int i = n2; i < n1; i++) {
		int sub = ((str1[i] - '0') - carry);

		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		} else
			carry = 0;

		str.push_back(sub + '0');
	}

	reverse(str.begin(), str.end());

	return str;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	while (cnt--) {
		int d;
		cin >> d;
		have |= 1 << d;
	}

	string INF = "1";
	F0R(j, 30) INF += "0";

	int k;
	cin >> k;
	string lo = "1", hi = INF, best;
	while (lo <= hi) {
		string add = sum(lo, hi);
		string mid = divide(add, 2);
		// int mid = (lo + hi) / 2;
		if (cnt_range(mid) >= k) {
			best = mid;
			hi = subtract(mid, "1");
		} else {
			lo = sum(mid, "1");
		}
	}
	assert(sz(best));
	cout << best << '\n';
}
