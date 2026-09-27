class Solution {
public:
    int hammingWeight(int n) {

        int number=0;

        while(n>0){
            if(n%2 != 0){
               number++;
            }
            n /= 2;
        }

        return number;
        
    }
};