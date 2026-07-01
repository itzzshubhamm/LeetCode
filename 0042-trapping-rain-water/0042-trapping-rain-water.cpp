class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int lmax=height[0];
        int rmax=height[n-1];
        int left=0; 
        int right=n-1;
        int water=0;

        while(left<right){
            lmax = max(lmax , height[left]);
            rmax = max(rmax , height[right]);

            if(lmax < rmax){
                water += lmax - height[left];
                left++;
            }
            else{
                water += rmax - height[right];
                right--;
            }
         
        }

        return water;
        
    }
};