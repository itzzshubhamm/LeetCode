class Solution {
public:
    int characterReplacement(string s, int k) { 

        int answer=INT_MIN;
        int left=0;
        unordered_map<char , int> mp;

        int maxFreq=INT_MIN;

        for(int right=0 ; right < s.size() ; right++){

            mp[s[right]]++;
            maxFreq = max(maxFreq , mp[s[right]]);
           
            while(left <= right && ((right-left)+1) - maxFreq > k){
                mp[s[left]]--;
                left++;
            }

            answer = max(answer , (right-left)+1);

        }

        return answer;
        
    }
};