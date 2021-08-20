#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test ll t; cin>>t; while(t--)
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;
const ll maxN = 100003;
ll power10[maxN];
ll dp2[2][maxN];
ll count(const string &s, ll n, bool isTightConstrained) {
	if (isTightConstrained == 0) {
		assert(n >= 0);
		return power10[n];
	}
  if (n == 0)
    return 1;
  assert(n >= 0 && n < maxN);
  ll& ans = dp2[isTightConstrained][n];
  if (~ans) return ans;
  ans = 0;
  ll upperBound = s[(ll)s.size() - n] - '0';
  for (ll i = 0; i <= upperBound; i++) {
    ans = (ans + count(s, n - 1, (i == upperBound)));
	if (ans >= MOD)
		ans -= MOD;
  }
  return ans;
}
ll dp[2][11][maxN];
ll recur(const string &s, ll n, ll prevDigit, bool isTightConstrained) {
  if (n == 0)
    return 0;
  assert(n >= 0 && n <= maxN);
  ll& ans = dp[isTightConstrained][prevDigit][n];
  if (~ans) return ans;
  ans = 0;
  ll upperBound = (isTightConstrained ? s[(ll)s.size() - n] - '0' : 9);
  for (ll i = 0; i <= upperBound; i++) {
    if (i != prevDigit) {
      ll contribution = (i * power10[n - 1]) % MOD;
      contribution = (contribution * count(s, n - 1, (i == upperBound) & isTightConstrained)) % MOD;
      ans = (ans + contribution) % MOD;
      // ans %= mod;
    }
    ans += recur(s, n - 1, i, isTightConstrained & (i == upperBound));
	if (ans >= MOD) ans -= MOD;
  }
  return ans;
}
ll brute(const string & s) {
  ll n = s.size();
  char prev = '!';
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (s[i] != prev) {
      ans = (ans + ((s[i] - '0') * power10[n - 1 - i] % MOD)) % MOD;
      // ans += ((s[i] - '0') * power10[n - i - 1]) % mod;
      // ans %= mod;
    }
    prev = s[i];
  }
  return ans;
}
void main2() {
  speed
  power10[0] = 1LL;
  for (ll i = 1; i < maxN; i++) {
    power10[i] = (power10[i - 1] * 10LL) % MOD;
  }
  test{
    ll nl, nr;
    string l, r;
    cin >> nl >> l >> nr >> r;

    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    ll ans = recur(r, r.size(), 10, 1);
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));

    ll ans2 = recur(l, l.size(), 10, 1);
    ans = (ans + MOD - ans2) % MOD;
    ans += brute(l); 
    ans %= MOD;
    cout << ans << '\n';
  }
}
static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack=(char *)malloc(stsize);
    send=stack+stsize-16;
    send=(char *)((uintptr_t)send/16*16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r" (send));
    func();
    asm volatile(
         "mov (%0), %%rsp\n"
         :
         : "r" (send));
    free(stack);
}
int main() {
    run_with_stack_size(main2, 1024*1024*1024);
    return 0;
}
