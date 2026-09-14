
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {

        int n = nums.size();
        vector<int> monotonic;

        long long countAns = 0;

        for(int i=0; i<n; i++){

            int currentNumber = nums[i];

            int left=0;
            int right = monotonic.size();

            while(left<right){
                int mid = left + (right - left)/2;
                
                if(monotonic[mid]<currentNumber){
                    left = mid+1;
                }else{
                    right = mid;
                }        
            }
            countAns += left;

            while(!monotonic.empty() && monotonic.back()>currentNumber){
                monotonic.pop_back();
            }

            monotonic.push_back(currentNumber);

        }

        return countAns;

        
    }
};