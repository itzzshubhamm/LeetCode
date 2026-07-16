class Solution {
public:
    int solve(vector<int>& nums, int start , int end){

        int next1 = 0; 
        int next2 = 0;
        int current;
        for(int i = end-1 ; i>=start ; i-- ){
            current = max(nums[i] + next2 , next1);
            next2 = next1;
            next1 = current;
        }

      

        return current;
 
    }


    int rob(vector<int>& nums) {
        
       int n = nums.size();

       if(n == 1){
        return nums[0];
       }
       if(n==0){
        return 0;
       }


        return max(solve(nums , 0  , nums.size() - 1) , solve(nums , 1  , n) );

        
    }
};