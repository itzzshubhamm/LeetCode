class Solution {
public:
    bool solve(vector<int>& nums , int index , int remainingSum , vector<vector<bool>>& dp){
        int n = nums.size();

        if(index >= n ){
            return false;
        }

        for(int i=0 ; i <= n; i++){
            dp[i][0] = true;
        }

        for(int i = 1 ; i <= remainingSum ; i++ ){
            dp[n][i] = false;
        }


        for(int i = n-1; i >= 0 ; i-- ){
            for(int j = remainingSum ; j >= 0 ; j--){
                bool take = false;
                if(j >= nums[i]){
                    take = dp[i+1][j - nums[i]];
                }
                dp[i][j]= take || dp[i+1][j];
            }
        } 

        return dp[0][remainingSum];
    }


    bool canPartition(vector<int>& nums) {

        int totalSum=0;
        for(int val : nums){
            totalSum += val;
        }

        if(totalSum%2 != 0){
            return false;
        }

        vector<vector<bool>> dp(nums.size()+1 , vector<bool> (totalSum , false));
        
        return solve(nums, 0, totalSum/2 , dp);
    }
};