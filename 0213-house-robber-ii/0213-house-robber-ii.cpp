class Solution {
public:
    int solve(vector<int>& nums , int index , vector<int>& dp , int maxSize){

        if(index >= maxSize){
            return 0;
        }

        if(dp[index] != -1){
           return dp[index];
        }

        return dp[index] =  max(nums[index] + solve(nums , index+2 , dp , maxSize) , solve(nums , index+1 , dp , maxSize));
 
    }


    int rob(vector<int>& nums) {
        
       int n = nums.size();

       if(n == 1){
        return nums[0];
       }
       if(n==0){
        return 0;
       }
       int m = nums.size() - 1;

        vector<int> dp1(n , -1);
        vector<int> dp2(n , -1);

        return max(solve(nums , 0 , dp1 , m) , solve(nums , 1 , dp2 , n) );

        
    }
};