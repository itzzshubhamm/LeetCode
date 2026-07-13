class Solution {
public:
   bool isPalindrome(string &s , int start , int end){
    while(start<=end){
        if(s[start]==s[end]){
            start++;
            end--;
            continue;
        }
        return false;
    }
    return true;
   }

   vector<vector<string>> answerToReturn;

   void palindromePartitioning(string& s , int start , vector<string>& currString){
    if(start >= s.size()){
        answerToReturn.push_back(currString);
        return;
    }

    for(int i=start ; i<s.size() ; i++){
        if(isPalindrome(s , start , i)){
            currString.push_back(s.substr(start , (i-start)+1));
            palindromePartitioning(s , i+1 , currString);
            currString.pop_back();
        }
    }

   }


    vector<vector<string>> partition(string s) {
        if(s.empty()){
            return answerToReturn;
        }
        
        vector<string> currString;
        palindromePartitioning(s , 0 , currString);
        return answerToReturn;

    }
};