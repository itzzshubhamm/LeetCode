class Solution {
public:

   int solve(int index , vector<int>& costs , vector<int>& dp){
    if(index >= costs.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    return dp[index] = costs[index] + min(solve(index+1 , costs ,dp), solve(index+2 , costs ,dp) );
   }
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
         vector<int> dp(n , -1);
         return min(solve(0 , cost , dp) , solve(1 , cost , dp));
    }
};