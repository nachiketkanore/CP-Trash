
class Solution {
public:
    int solve(int N, int a, vector<int> x) {
        sort(x.begin(), x.end());
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int best = abs(x[i] - a);
            int best2 = 0;
            if (i != 0) {
                best2 = max(best2, abs(x[0] - a));
            }
            if (i != N - 1) {
                best2 = max(best2, abs(x[N - 1] - a));
            }
            ans = max(ans, best + best2);
        }
        return ans;
    }
};
