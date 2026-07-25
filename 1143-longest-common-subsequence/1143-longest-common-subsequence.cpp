class Solution {
public:
    int solve(string& s1 , string& s2){

       vector<vector<int>> dp ( s1.size() + 1 , vector<int> ( s2.size() + 1 , -1));

       int m = s1.size();
       int n = s2.size();

       for(int i = 0 ; i <= s1.size() ; i++){
        dp[i][n] = 0;
       }
       for(int i = 0 ; i <= s2.size() ; i++){
        dp[m][i] = 0;  
       }

       for(int i = m-1; i >= 0; i--){
          for(int j = n-1; j>=0; j--){
              if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
              }
              else{
                dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
              }
          }
       }
       
       return dp[0][0];

    }

    int longestCommonSubsequence(string text1, string text2) { 
        
        return solve(text1, text2);
    }
};