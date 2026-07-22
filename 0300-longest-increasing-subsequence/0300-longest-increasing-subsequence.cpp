class Solution {
public:
    int solve(vector<int>& nums , int index , int prevIndex , vector<vector<int>>& dp){

        if(index == nums.size()){
           return 0;
        }

        if(dp[index][prevIndex+1] != -1){
            return dp[index][prevIndex+1];
        }

        int take=0;
        
        if(prevIndex == -1 || (nums[prevIndex] < nums[index])){
            take = 1 + solve(nums, index+1, index,dp);
        }
        return dp[index][prevIndex+1] = max(take , solve(nums, index+1, prevIndex, dp));
    }


    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp( nums.size()+1 , vector<int> ( nums.size()+1 , -1 ) );
        return solve(nums , 0 , -1 , dp);
    }
};