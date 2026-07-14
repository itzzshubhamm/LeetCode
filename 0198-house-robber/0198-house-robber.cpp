class Solution {
public:
    // int solve(vector<int>& nums , int index , vector<int>& dp){
    //       if(index >=nums.size()){
    //         return 0;
    //       }
    //       if(dp[index] != -1){
    //         return dp[index];
    //       }

    //       return dp[index] = max ( nums[index] + solve(nums , index+2 , dp) , solve(nums , index+1 , dp) );

    // }

    int solve(vector<int>& nums){
         int n = nums.size();
         if(n==1){
            return nums[0];
         }
         if(n==2){
            return max(nums[0] , nums[1]);
         }
         int prev2 = nums[0];
         int prev1 = max( prev2 , nums[1]);
         int current;

        for(int i=2 ; i<n;i++ ){
            current = max(prev1 , prev2 + nums[i]);
            prev2 = prev1;
            prev1=current;
        }

        return current;     
    }



    int rob(vector<int>& nums) {

        return solve(nums);
        
    }
};