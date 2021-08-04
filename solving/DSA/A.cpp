#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 5e5 + 5;
const int LOG = 35;

int n, X, a[N], cnt[LOG][N];

void main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(a.begin(), a.end());
	bool ok = true;
	for (int i = 1; i < n; i++) ok &= a[i-1] == a[i];
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	int T;
	cin >> T;
	while (T--) {
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													jjjjjjjjja;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												[

												]
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int n;
	int t;
	cin >> n >> t;
	{
	}
	{
		{
		}}
}

void test() {
	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A+N);
	cout << A[N-1] - A[0] << endl;
}

int input() {
	int ret;
	scanf("%lld", &ret);
	return ret;
	{

	}
}

void precomp() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		a.push_back(input());
	}
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> X;
		FOR (i,1,n) {
			cin >> a[i];
			F0R (bit,LOG) cnt[bit][i] = 0;
			F0R (bit,LOG)
				cnt[bit][i] += cnt[bit][i-1] + (a[i] >> bit & 1LL);
		}

		auto get_OR = [&](int L, int R) {
			int ret = 0;
			F0R (bit,LOG) if (cnt[bit][R] - cnt[bit][L - 1] > 0)
				ret |= 1LL << bit;
			return ret;
		};

		vector<pair<int,int>> answer;

		FOR (i,1,n) {
			int lo = i, hi = n;
			int best = -1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (get_OR(i, mid) >= X) best = mid, hi = mid - 1;
				else lo = mid + 1;
			}
			if (~best) {
				if (answer.empty()) answer.push_back(make_pair(i, best));
				else {
					int prev_best = answer.back().second - answer.back().first;
					if (prev_best > best - i) {
						answer.clear();
						answer.push_back(make_pair(i, best));
					} else if (prev_best == best - i) {
						answer.push_back(make_pair(i, best));
					}
				}
			}
		}

		sort(ALL(answer));
		for (int i = 1; i < sz(answer); i++) {
			int prev = answer[i-1].second - answer[i-1].first;
			int now = answer[i].second - answer[i].first;
			assert(prev == now);
		}
		cout << sz(answer) << '\n';
		for (auto [L, R]: answer) cout << L << ' ' << R << '\n';
	}
}

