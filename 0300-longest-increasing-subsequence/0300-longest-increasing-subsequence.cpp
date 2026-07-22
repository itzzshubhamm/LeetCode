class Solution {
public:
    int solve(vector<int>& nums , int index , int prevIndex , vector<vector<int>>& dp){
        int n = nums.size();
       
       for(int i = -1 ; i <= n-1 ; i++){
           dp[n][i+1] = 0;
       }


       for(int i = n-1 ; i >= 0 ; i--){
        for(int j = i-1 ; j >= -1 ; j--){
            int take=0;
            if(j == -1 || nums[j] < nums[i] ){
                take = 1 + dp[i+1][i+1];
            }
            dp[i][j+1] = max(take , dp[i+1][j+1]);
        }

       }

       return dp[0][0];
    }


    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp( nums.size()+1 , vector<int> ( nums.size()+1 , -1 ) );
        return solve(nums , 0 , -1 , dp);
    }
};