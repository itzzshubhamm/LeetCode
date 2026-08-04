class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int fuel = 0;
        int total = 0;

        for(int i=0 ; i < gas.size() ; i++){
            int diff = gas[i] - cost[i];
            fuel += diff;
            total += diff;
            if(fuel < 0){
                start = i+1;
                fuel = 0;
            }
        }

        return total >= 0 ? start : -1;
        
    }
};                                                                                                                                    