#include <bits/stdc++.h>
using namespace std;

// solution begins

void go(int l, int r, string val, set<int>& palsg) {
	if (l > r) {
		palsg.insert(stoi(val));
	} else {
		for (int put = (l == 0); put < 10; put++) {
			string next_val = val;
			next_val[l] = next_val[r] = (char)(put + '0');
			go(l + 1, r - 1, next_val, palsg);
		}
	}
}

vector<int> generate_pals() {
	set<int> palsg;
	for (int digits = 1; digits <= 9; digits++) {
		string val = string(digits, '.');
		go(0, digits - 1, val, palsg);
	}
	return vector<int>(palsg.begin(), palsg.end());
}

vector<int> pals = generate_pals();

class Solution {
	public:
	long long minimumCost(vector<int> A) {
		long long ans = 1e18;
		const int N = A.size();
		vector<long long> pref(N);
		sort(A.begin(), A.end());
		for (int i = 0; i < N; i++) {
			pref[i] = 1ll * A[i] + (i ? pref[i - 1] : 0);
		}
		for (int make : pals) {

			int id = lower_bound(A.begin(), A.end(), make) - A.begin();
			// suffix sum
			long long suff = 0, suff_cnt = 0;
			if (id < N) {
				suff = pref[N - 1] - (id ? pref[id - 1] : 0);
				suff_cnt = N - id;
			}
			// prefix sum
			long long prev = 0, prev_cnt = 0;
			if (id - 1 >= 0) {
				prev = pref[id - 1];
				prev_cnt = id;
			}

			long long cost = suff - suff_cnt * make + 1ll * make * prev_cnt - prev;
			ans = min(ans, cost);
		}
		return ans;
	}
};
// solution ends

int32_t main() {
	Solution solution;

	cout << solution.minimumCost({ 1, 2, 3, 4, 5 }) << endl;
	cout << solution.minimumCost({ 10, 12, 13, 14, 15 }) << endl;
	cout << solution.minimumCost({ 22, 33, 22, 33, 22 }) << endl;
	cout << solution.minimumCost({ 493394, 291777192, 2521252, 443787344, 152959251, 531656135, 144868441, 563777365, 3527253, 227020722, 250868052,
			5762675, 899191998, 4694964, 358838853, 641747146, 231404132, 85155158, 371141173, 656191656, 722060227, 877474778, 324878423, 414848414,
			92029, 940282049, 95844859, 50511505, 997919799, 827565728, 731373137, 654222456, 790151097, 5121215, 733424337, 3600063, 945252549,
			140626041, 563252365, 249717942, 930585039, 363151363, 905797509, 447090744, 622020226, 303616303, 411525114, 68222286, 900272009,
			642949246, 21244212, 321878123, 908373809, 951434159, 645070546, 292878292, 430151034, 56277265, 824212428, 395373593, 845454548, 468202864,
			2038302, 542202245, 168111861, 260969062, 203656302, 8138318, 625909526, 448858844, 318030813, 7821287, 120666021, 825303528, 217848712,
			51199115, 639585936, 79397, 556383655, 730434037, 1272721, 1321231, 431777134, 304333403, 148515841, 69844896, 786434687, 778717877,
			754242457, 446323644, 462141264, 991626199, 402939204, 85866858, 692464296, 685585586, 502373205, 611828116, 631727136, 236767632 })
		 << endl;

	return 0;
}
