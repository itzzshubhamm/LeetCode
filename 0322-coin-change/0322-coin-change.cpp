class Solution {
public:
    const int INF = 1e9;
    int solve(vector<int>& coins , int amount , vector<int>& dp){

        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INF;
        }
        if(dp[amount] != -1 ){
          return dp[amount];
        }

        int answer = INF;

        for(int coin : coins){

            answer = min (answer , 1 + solve(coins , amount - coin , dp ));

        }


        return dp[amount] = answer;

    
    }


    int coinChange(vector<int>& coins, int amount) {
   
       vector<int> dp( amount+1 , -1);
 
       int ans = solve(coins, amount, dp);

       if(ans != INF){
        return ans;
       }
       else{
        return -1;
       }
  
    }
};