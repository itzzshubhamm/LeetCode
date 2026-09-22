class Solution {
public:
    double myPow(double x, int n) {
        
long long N = n;
        double result = 1;
        if(N<0){
            x = 1/x;
            N = -N;
        }

        while(N>0){
            if(N%2 == 1){
                result *= x;
            }
            x *= x;
            N = N/2; 
        }

        return result;
        
    }
};