class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {

        int m = matrix.size();
        int n = matrix[0].size();

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 1;

        // Up
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            ans = max(ans, 1 + solve(matrix, i - 1, j, dp));
        }

        // Down
        if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
            ans = max(ans, 1 + solve(matrix, i + 1, j, dp));
        }

        // Left
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            ans = max(ans, 1 + solve(matrix, i, j - 1, dp));
        }

        // Right
        if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
            ans = max(ans, 1 + solve(matrix, i, j + 1, dp));
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1 , vector<int> (n+1 , -1));

        int ans = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, solve(matrix, i, j , dp));
            }
        }

        return ans;
    }
};