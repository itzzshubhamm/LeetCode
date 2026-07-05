class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> numOfDay(temperatures.size() , 0);
        stack<int> st;


        for(int i=0 ; i < temperatures.size() ; i++){

          while(!st.empty() && temperatures[st.top()] < temperatures[i]){
            numOfDay[st.top()] = i - st.top();
            st.pop();
          }

           if(st.empty() || temperatures[st.top()] >= temperatures[i] ){
              st.push(i);
           }

        }

        return numOfDay;
        
    }
};