class Solution {
public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size() - 2;

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        // length of interval
        for (int len = 1; len <= n; len++) {

            for (int left = 1; left <= n - len + 1; left++) {

                int right = left + len - 1;

                for (int k = left; k <= right; k++) {

                    int coins =
                        nums[left - 1] * nums[k] * nums[right + 1];

                    dp[left][right] = max(
                        dp[left][right],
                        coins +
                        dp[left][k - 1] +
                        dp[k + 1][right]
                    );
                }
            }
        }

        return dp[1][n];
    }
};