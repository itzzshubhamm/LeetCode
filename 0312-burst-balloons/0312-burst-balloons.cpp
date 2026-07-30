class Solution {
public:
    
    int solve(vector<int>& nums, int left, int right, vector<vector<int>>& dp){
        
        if(left > right){
           return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans=0;
        for(int k = left ; k <= right ; k++){
        int coins = nums[left-1] * nums[k] * nums [right+1];
        int leftPortion = solve(nums , left , k-1 , dp);
        int rightPortion = solve(nums , k+1 , right , dp);
        ans = max(ans , coins + leftPortion + rightPortion);     
        }

        return dp[left][right] = ans;

    }
    
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        vector<vector<int>> dp( nums.size()+1 , vector<int> ( nums.size() , -1 ) );
        return solve(nums , 1 , nums.size()-2 , dp);
        
    }
};