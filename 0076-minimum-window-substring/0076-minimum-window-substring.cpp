class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() < t.size()){
            return "";
        }
        
        unordered_map<char , int> targetMp;
        unordered_map<char , int> substringMp;
        
        for(char val : t){
            targetMp[val]++;
        }

        int need = targetMp.size();

        int left=0;
        int startOfSubString=0;
        int minLen = INT_MAX;
        int formed=0;

        for(int right=0 ; right < s.size() ; right++){
            substringMp[s[right]]++;

            if(substringMp[s[right]] == targetMp[s[right]]){
                formed++;
            }

            while(left<=right && formed == need){
                if((right-left)+1 < minLen){
                    minLen = (right-left) +1;
                    startOfSubString = left;
                }
                substringMp[s[left]]--;
                if(substringMp[s[left]] < targetMp[s[left]]){
                 formed--;
                }
                left++;
            }


        }

        if(minLen == INT_MAX || minLen == 0){
            return "";
        }

        return s.substr(startOfSubString , minLen);


    }
};