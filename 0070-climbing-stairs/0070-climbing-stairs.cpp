class Solution {
public:

    // int climbStairs(int n) {
    //     if(n<=1){
    //         return 1;
    //     }
    //     return climbStairs(n-2) + climbStairs(n-1);
        
    // }

   int solve(int n , vector<int>& dp){

       if(n<=1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = solve(n-2 , dp) + solve(n-1 , dp);

   }


    
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n,dp);
        
    }





};