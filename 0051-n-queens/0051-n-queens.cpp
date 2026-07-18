class Solution {
public:

   vector<vector<string>> answer;

   bool isSafe(vector<string>& board , int row , int col){

    int n = board.size();

    for(int i=row-1 ; i >= 0 ; i--){
        if(board[i][col] == 'Q'){
           return false;
        }
    }

    int i=row-1;
    int j=col-1; 
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    
    i=row-1;
    j=col+1;
    while(i>=0 && j<n){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }

    return true;
   }

   void solution(vector<string>& board , int n , int row ){

      if(row==n){
        answer.push_back(board);
        return;
      }
      for(int col=0 ; col < n ; col++){
        if(isSafe(board , row , col)){
            board[row][col] = 'Q';
            solution(board , n , row + 1);
            board[row][col] = '.';
        }
      } 

   }


    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n , string (n , '.'));

        solution(board , n , 0);

        return answer;
 
        
    }
};