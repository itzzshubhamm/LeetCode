class Solution {
public:
    int solve(int i, int j, vector<int>& piles, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
          return dp[i][j];
        }

        int takeStart = piles[i] - solve(i+1, j, piles, dp);
        int takeEnd = piles[j] - solve(i, j-1, piles, dp);

        return dp[i][j] = max(takeStart, takeEnd);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(0, n-1, piles, dp) > 0;
    }
};