class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currentEnd = 0;
        int farthestPoint = 0;
        int jumps=0;

        for(int i=0 ; i < n-1 ; i++ ){
            farthestPoint = max(farthestPoint , i + nums[i]);
            if(i == currentEnd){
                jumps++;
                currentEnd = farthestPoint;
            }
        }

        return jumps;
        
    }
};