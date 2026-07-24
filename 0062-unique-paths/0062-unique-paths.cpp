class Solution {
public:
    int solve( int m , int n ){
 
       
        vector<int> next(n ,1);
 
        for(int i=m-2; i >= 0; i--){
            vector<int> curr ( n , 0);
            curr[n-1]=1;
            for(int j=n-2 ; j>= 0 ; j--){
                curr[j] = next[j] + curr[j+1];
            }
            next = curr;
        }
 
 
        return next[0];
    }
 
    int uniquePaths(int m, int n) {
 
        return solve(m, n);
       
    }
};
