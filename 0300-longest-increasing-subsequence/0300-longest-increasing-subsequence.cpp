class Solution {
public:
    int solve(vector<int>& nums , int index , int prevIndex){
        int n = nums.size();

        vector<int> next(n+1 , 0);
        vector<int> curr(n+1 , 0);

       for(int i = n-1 ; i >= 0 ; i--){
        for(int j = i-1 ; j >= -1 ; j--){
            int take=0;
            if(j == -1 || nums[j] < nums[i] ){
                take = 1 + next[i+1];
            }
            curr[j+1] = max(take , next[j+1]);
        }
        next = curr;

       }

       return next[0];
    }


    int lengthOfLIS(vector<int>& nums) {
        return solve(nums , 0 , -1);
    }
};