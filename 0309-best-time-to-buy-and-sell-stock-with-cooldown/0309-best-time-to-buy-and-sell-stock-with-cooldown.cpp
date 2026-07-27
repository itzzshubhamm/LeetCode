class Solution {
public:

    int maxProfit(vector<int>& prices) {     

     vector<vector<int>> dp( prices.size()+2 , vector<int> ( 2 , 0 ));


    for(int index = prices.size() - 1 ; index >= 0 ; index-- ){

      
           int take = -prices[index] + dp[index+1][0];
           int skip = dp[index+1][1];
           dp[index][1] = max( take , skip);
        
       
            int sell = prices[index] + dp[index+2][1];
            int hold = dp[index+1][0];
            dp[index][0] = max(sell , hold);
    }      

    return dp[0][1];
        
    }
};