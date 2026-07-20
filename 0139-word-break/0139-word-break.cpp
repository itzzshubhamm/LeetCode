class Solution {
public:

    int solve(string& s , unordered_set<string>& wordDict , int start , vector<int>& dp){
       
       if(start == s.size()){
         return true;
       }
       if(dp[start] != -1){
         return dp[start];
       }

       for(int end = start ; end < s.size() ; end++){
         string subs = s.substr(start , (end - start) + 1) ;
         if(wordDict.find(subs) != wordDict.end()){
            if(solve(s , wordDict , end+1 , dp)){
                return dp[start] = 1;
            }
         }
       }

       return dp[start] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words( wordDict.begin() , wordDict.end());
        vector<int> dp(s.size() , -1);
        int ans = solve(s, words ,0 ,dp);
        
        if(ans == 1){
            return true;
        }else{
           return false;
        }
    }
};