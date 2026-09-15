
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {

        int n = nums.size();
        vector<int> monotonicStack;

        long long countAns = 0;

        for(int i=0; i<n; i++){

            int currentNumber = nums[i];

            int left=0;
            int right = monotonicStack.size();

            while(left<right){
                int mid = left + (right - left)/2;
                
                if(monotonicStack[mid]<currentNumber){
                    left = mid+1;
                }else{
                    right = mid;
                }        
            }
            countAns += left;

            while(!monotonicStack.empty() && monotonicStack.back()>currentNumber){
                monotonicStack.pop_back();
            }

            monotonicStack.push_back(currentNumber);

        }

        return countAns;

        
    }
};