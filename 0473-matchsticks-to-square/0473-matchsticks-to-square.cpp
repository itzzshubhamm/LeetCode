class Solution {
public:
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index,
                   int& target) {
        if (index == matchsticks.size()) {
            return true;
        }
        for(int i=0; i<4; i++){
            if(matchsticks[index] + sides[i] > target ){
                continue;
            }
            sides[i] += matchsticks[index];
            if(backtrack(matchsticks, sides, index+1, target)){
                return true;
            }
            sides[i] -= matchsticks[index];
        }

        return false;

    }

    bool makesquare(vector<int>& matchsticks) {

        int target = 0;

        for (int val : matchsticks) {
            target += val;
        }

        if (target % 4 != 0) {
            return false;
        }

        target /= 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target) {
            return false;
        }

        vector<int> sides(4,0);

        if (backtrack(matchsticks, sides, 0, target)) {
            return true;
        }

        return false;
    }
};