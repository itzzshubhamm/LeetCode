class Solution {
public:

    int solve(int amount , vector<int>& coins , int index){
        vector<vector<long long>> dp( coins.size()+1 , vector<long long> ( amount+1 , 0 ));

        int n = coins.size();

        for(int i =0 ; i <= n ; i++){
            dp[i][0] = 1;
        }

        for(int i = n-1 ; i >=0 ; i--){
            for(int j = 0 ; j <= amount ; j++){
                int take = 0;
                if(coins[i] <= j ){
                  take = dp[i][j-coins[i]];
                }
                dp[i][j] = take + dp[i+1][j];
            }
        }

        return dp[0][amount];

    }

    int change(int amount, vector<int>& coins) {
        return solve(amount , coins, 0);
    }
};