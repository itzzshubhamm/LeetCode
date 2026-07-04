class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        stack<double> st;
        vector<pair<int , double>> timePosition;

        for(int i=0 ; i < position.size() ; i++){
            double timeTo = double(target-position[i])/speed[i];
            timePosition.push_back({position[i] , timeTo});
        }

        sort(timePosition.begin() , timePosition.end() , greater<pair<int , double>>());

        for(auto val : timePosition){
            if(st.empty() || st.top() < val.second){
                st.push(val.second);
            }  
        }

        return st.size();

        
    }
};