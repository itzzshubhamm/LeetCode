class Solution {
public:
    int solve(vector<int>& coins , int index , int amount , vector<vector<int>>& dp){

        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(index >= coins.size()){
            return INT_MAX;
        }

        if(dp[index][amount] != -1 ){
          return dp[index][amount]; 
        }

        int coinCount = solve(coins , index , amount - coins[index] , dp);

        if(coinCount != INT_MAX){
            coinCount += 1;
        }  

        return dp[index][amount] = min( coinCount , solve(coins , index+1 , amount , dp) );

    }


    int coinChange(vector<int>& coins, int amount) {

       int n = coins.size(); 
   
       vector<vector<int>> dp( n , vector<int> (amount+1 , -1));
 
       int ans = solve(coins, 0, amount, dp);

       if(ans != INT_MAX){
        return ans;
       }
       else{
        return -1;
       }
  
    }
};