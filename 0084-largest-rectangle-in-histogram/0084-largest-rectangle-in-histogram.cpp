class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int area=0;

        for(int i=0 ; i <= heights.size() ; i++){

            int currentHeight = (i == heights.size()) ? 0 : heights[i];

           while(!st.empty() && currentHeight < heights[st.top()]){

              int width;
              int height = heights[st.top()];

              st.pop();

              if(st.empty()){
                width = i;
              }else{
                width = (i - st.top()) - 1 ;
              }

              area = max (area , height*width);

           }

           st.push(i);



        }

return area;

        
    }
};