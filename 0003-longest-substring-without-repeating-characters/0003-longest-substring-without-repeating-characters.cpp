class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;
        int answer=INT_MIN;
        int left=0;

        if(s.size() == 0){
            return 0;
        }

       for(int right=0 ; right<s.size() ; right++){
       
            while(left<=right && st.find(s[right]) != st.end()){
                left++;
                st.erase(s[left-1]);
            }
            st.insert(s[right]);
            answer = max((right-left)+1 , answer);
       }

       return answer;

    }
};