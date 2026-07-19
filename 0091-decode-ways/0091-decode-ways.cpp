class Solution {
public:

    int ways(string& s , int index , vector<int>& dp){

        if(index == s.size()){
            return 1;
        }
        if(s[index] == '0'){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int way = ways(s , index+1 , dp);

        if(index+1 != s.size()){
            int num = ((s[index] - '0')*10 + s[index+1]-'0');

            if( 10 <= num && num <= 26){
               way += ways(s , index+2 , dp);
            }
        }


        return dp[index] = way;
    }


    int numDecodings(string s) {

        vector<int> dp(s.size() , -1);

        if(s.size() == 0){
            return 0;
        }
        if(s.size() == 1){
            if(s[0]== '0'){
                return 0;
            }
            else return 1;
        }

        return ways(s , 0 , dp);
 
    }
};