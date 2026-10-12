class Solution {
public:
    int solve(vector<int>& nums, int remaining, vector<int>& dp){

        if(remaining < 0){
            return 0;
        }
        if(remaining == 0){
            return 1;
        }

        if(dp[remaining] != -1){
            return dp[remaining];
        }

        int total = 0;

        for(int val : nums){
            total += solve(nums, remaining - val, dp);
        }

        return dp[remaining]=total;

    }

    int combinationSum4(vector<int>& nums, int target) {
     vector<int> dp(target+1,-1);
     return solve(nums, target, dp);
    }
};