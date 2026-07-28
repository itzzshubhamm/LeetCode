class Solution {
public:
    int numDistinct(string s, string t) {
       vector<vector<long long>> dp(s.size() + 1, vector<long long>(t.size() + 1, 0));
       const long long LIM = INT_MAX;
        int m = s.size();
        int n = t.size();

        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = min(LIM , dp[i + 1][j + 1] + dp[i+1][j]) ;
                }
                else{
                dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};