class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        double answer;
        
        if(m>n){
            return findMedianSortedArrays(nums2 , nums1);
        }
          
        int totalLeft = (m+n)/2;
        int left = 0;
        int right = m;
        
        while(left <=right){
             int partitionA = left + (right - left)/2;
             int partitionB = totalLeft - partitionA;

             int Aleft = (partitionA == 0) ? INT_MIN : nums1[partitionA-1];
             int Aright = (partitionA == m) ? INT_MAX : nums1[partitionA];

             int Bleft = (partitionB == 0) ? INT_MIN : nums2[partitionB-1];
             int Bright = (partitionB == n) ? INT_MAX : nums2[partitionB];

             if(Aleft <= Bright && Bleft <= Aright){
                if((m+n)%2 == 0){
                    return answer = (max(Aleft , Bleft) + min(Aright , Bright))/2.0;
                }
                else{
                    return min(Aright , Bright);
                }
             }else{
                if (Aleft > Bright) {
                    right = partitionA - 1;
                }
                else {
                    left = partitionA + 1;
                }
             }}

        return 0.0;
    }
};