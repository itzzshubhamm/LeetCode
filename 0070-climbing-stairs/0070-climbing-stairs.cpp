class Solution {
public:

// Raw recurssion method
    // int climbStairs(int n) {
    //     if(n<=1){
    //         return 1;
    //     }
    //     return climbStairs(n-2) + climbStairs(n-1);
        
    // }


    // DP Memoization method

//    int solve(int n , vector<int>& dp){

//        if(n<=1){
//             return 1;
//         }

//         if(dp[n] != -1){
//             return dp[n];
//         }

//         return dp[n] = solve(n-2 , dp) + solve(n-1 , dp);

//    }
   

   int solve(int n){

       if(n<=1){
            return 1;
        }

        int prev1=1;
        int prev2=1;
        int current;

        for(int i=2 ; i<=n ; i++){
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;   
        }


       return current;

   }


    
    int climbStairs(int n) {
     
        return solve(n);
        
    }





};