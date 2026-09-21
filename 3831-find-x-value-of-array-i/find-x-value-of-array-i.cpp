class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for (long long v : nums) {
            v %= k;
            vector<long long> ndp(k);

            ndp[v]++;

            for (int r = 0; r < k; r++) {
                ndp[(r * v) % k] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = move(ndp);
        }

        return ans;
    }
};