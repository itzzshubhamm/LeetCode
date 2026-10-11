
class Solution {
public:
    int solve(int i, int remaining, vector<int>& stones,
              vector<vector<int>>& dp) {
        if (i == stones.size()) {
            return 0;
        }

        if (dp[i][remaining] != -1) {
            return dp[i][remaining];
        }

        int skip = solve(i + 1, remaining, stones, dp);
        int take = 0;

        if (stones[i] <= remaining) {
            take = stones[i] + solve(i + 1, remaining - stones[i], stones, dp);
        }

        return dp[i][remaining] = max(take, skip);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;

        for (int stone : stones) {
            totalSum += stone;
        }

        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int bestSum = solve(0, target, stones, dp);

        return totalSum - 2 * bestSum;
    }
};
