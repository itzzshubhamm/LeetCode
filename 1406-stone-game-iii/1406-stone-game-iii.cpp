class Solution {
public:
    // int solve(int i, vector<int>& stoneValue, vector<int>& dp) {
    //     int n = stoneValue.size();
    //     if (i >= n) {
    //         return 0;
    //     }

    //     if (dp[i] != -1) {
    //         return dp[i];
    //     }

    //     int currentAdv = INT_MIN;
    //     int sum = 0;

    //     for (int j = i; j < n && j < i + 3; j++) {

    //         sum += stoneValue[j];

    //         currentAdv = max(currentAdv, sum - solve(j + 1, stoneValue, dp));
    //     }

    //     return dp[i] = currentAdv;
    // }

    string stoneGameIII(vector<int>& stoneValue) {

        vector<int> dp(stoneValue.size() + 1, 0);
        int n = stoneValue.size();

        for (int i = n-1; i >= 0; i--) {

            int currentAdv = INT_MIN;
            int sum = 0;

            for (int j = i; j < n && j < i + 3; j++) {
                sum += stoneValue[j];
                currentAdv = max(currentAdv, sum - dp[j + 1]);
            }

            dp[i] = currentAdv;
        }



        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }

        return "Tie";
    }
};