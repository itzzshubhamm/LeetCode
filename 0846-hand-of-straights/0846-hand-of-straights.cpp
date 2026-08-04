class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        vector<bool> used(n,false);

        sort( hand.begin() , hand.end());
        for(int i =0 ; i < hand.size() ; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            int prev = hand[i];
            for(int cnt = 1 ; cnt < groupSize ; cnt++){
                    bool found = false;
                    for(int j = i+1 ; j < hand.size() ; j++ ){
                         if(!used[j] && hand[j] == prev+1){
                            found = true;
                            used[j]=true;
                            prev = hand[j];
                            break;
                         } 
                    }
                    if(!found){
                       return false; 
                    }

            } 
        }

        return true;
        
    }
};