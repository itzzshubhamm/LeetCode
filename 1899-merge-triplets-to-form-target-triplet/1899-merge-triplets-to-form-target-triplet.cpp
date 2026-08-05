class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        bool first=false;
        bool second=false;
        bool third=false;

        for(auto val : triplets){
            if(val[0] > target[0] || val[1] > target[1] || val[2] > target[2]){
                continue;
            }
            if(val[0] == target[0]) first = true;
            if(val[1] == target[1]) second = true;
            if(val[2] == target[2]) third = true;

            if(first && second && third){
                return true;
            }
         
        }

        return false;
        
    }
};