class Solution {
public:
    int solve(vector<int>& nums , int target , int index , int curr , int offset , vector<vector<int>>& dp ){
        int n = nums.size();
               
        if(index == n){
            return curr == target;
        }

        if(dp[index][curr + offset] != -1){
            return dp[index][curr + offset];
        }

        return dp[index][curr + offset] = solve(nums , target , index+1 ,  curr - nums[index] , offset , dp) + solve(nums , target , index+1 , curr + nums[index] , offset , dp);

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int offset = accumulate(nums.begin() , nums.end() , 0);

        vector<vector<int>> dp( nums.size() + 1 , vector<int> ( 2 * offset + 1 , -1  ));
        return solve(nums , target , 0 , 0 , offset , dp);
    }
};