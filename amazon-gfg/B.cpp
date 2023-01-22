
class Solution {
	public:
	long long colosseum(int N, vector<int> A) {
		// 1 1 1 2 3 5
		// 1 1 5 3 7 7
		using ll = long long;
		const ll INF = 1e18;
		const int len = A.size();

		multiset<int> T;
		ll sum = 0;

		vector<ll> pref(len, -INF), suff(len, INF);

		for (int i = 0; i < len; i++) {
			T.insert(A[i]);
			sum += A[i];

			if (T.size() > N) {
				int rem = *T.begin();
				sum -= rem;
				T.erase(T.find(rem));
			}
			if (T.size() == N) {
				pref[i] = sum;
			}
		}

		sum = 0;
		T.clear();

		for (int i = len - 1; i >= 0; i--) {
			T.insert(A[i]);
			sum += A[i];

			if (T.size() > N) {
				int rem = *T.rbegin();
				sum -= rem;
				T.erase(T.find(rem));
			}
			if (T.size() == N) {
				suff[i] = sum;
			}
		}

		for (int i = 1; i < len; i++) {
			pref[i] = max(pref[i], pref[i - 1]);
		}
		for (int i = len - 2; i >= 0; i--) {
			suff[i] = min(suff[i], suff[i + 1]);
		}

		ll ans = -INF;
		for (int i = N - 1; i < len - N; i++) {
			ll s1 = pref[i], s2 = suff[i + 1];
			if (s1 != -INF && s2 != -INF) {
				// cout << i << ' ' << s1 << ' ' << s2 << endl;
				ans = max(ans, s1 - s2);
			}
		}

		return ans;
	}
};
