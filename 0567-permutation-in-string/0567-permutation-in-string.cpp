class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s2.size() < s1.size()){
            return false;
        }

        vector<int> targetFreq(26, 0);
        vector<int> currentFreq(26, 0);

        int wind = s1.size();

        for (char val : s1) {
            targetFreq[val - 'a']++;
        }

        for (int i = 0; i < wind; i++) {
            currentFreq[s2[i] - 'a']++;
        }
        if (currentFreq == targetFreq) {
            return true;
        }

        int left = 0;

        for (int right = wind ; right < s2.size(); right++) {

            currentFreq[s2[right] - 'a']++;
            currentFreq[s2[right - wind] - 'a']--;

            if (currentFreq == targetFreq) {
                return true;
            }
        }

        return false;
    }
};