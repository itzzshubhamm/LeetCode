class Solution {
public:
    int solve(vector<int>& nums , int target , int index , int curr){
        int n = nums.size();
        
        if(target == curr && index == n){
            return 1;
        }        
        if(index == n){
            return 0;
        }

        return solve(nums , target , index+1 , curr - nums[index]) + solve(nums , target , index+1 , curr + nums[index]);

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , 0 , 0);
    }
};