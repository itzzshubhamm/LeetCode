class Solution {
public:

    int solve(vector<int>& prices , int index ,  int canBuy ,  vector<vector<int>>& dp){

        if(index >= prices.size()){
           return 0;
        }

        if(dp[index][canBuy] != -1){
            return dp[index][canBuy];
        }

        if(canBuy){
           int take = -prices[index] + solve(prices , index + 1 , false , dp);
           int skip = solve(prices , index + 1 , true , dp);

           return dp[index][canBuy] = max( take , skip); 
        }
        else{
            int sell = prices[index] + solve(prices , index + 2 , true , dp);
            int hold = solve(prices , index + 1 , false , dp);

            return dp[index][canBuy] = max(sell , hold);
        }    

    }

    int maxProfit(vector<int>& prices) {

       vector<vector<int>> dp( prices.size()+1 , vector<int> ( 2 , -1 )); 

       return solve(prices , 0 , true , dp);
        
    }
};