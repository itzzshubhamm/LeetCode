class Solution {
public:
    bool solve(vector<int>& nums , int index , int remainingSum , vector<vector<int>>& dp){

        if(remainingSum == 0){
           return true; 
        }
        if(remainingSum < 0){
           return false; 
        }
        if(index >= nums.size()){
            return false;
        }
        if(dp[index][remainingSum] != -1){
            return dp[index][remainingSum];
        }
    

        return dp[index][remainingSum] = solve(nums, index+1, remainingSum - nums[index], dp) || solve(nums, index+1, remainingSum, dp);
    }


    bool canPartition(vector<int>& nums) {

        int totalSum=0;
        for(int val : nums){
            totalSum += val;
        }

        if(totalSum%2 != 0){
            return false;
        }

        vector<vector<int>> dp(nums.size() , vector<int> (totalSum , -1));
        
        return solve(nums, 0, totalSum/2 , dp);
    }
};