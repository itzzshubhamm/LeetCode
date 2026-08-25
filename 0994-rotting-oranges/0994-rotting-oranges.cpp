class Solution {
public:
    

    int orangesRotting(vector<vector<int>>& grid) {
         int rows = grid.size();
         int cols = grid[0].size();
         

        queue<pair<int,int>> q;
        int fresh=0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    fresh++;
                    continue;
                }
                if(grid[i][j] == 0){
                    continue;
                }
                q.push({i,j});
            }
        }
        int time=0;

        while(!q.empty()){
            
            int size = q.size();
            bool rotted=false;

            for(int i=0; i<size; i++){
                auto [r , c] = q.front();
                q.pop();

                if(r-1 >=0 && grid[r-1][c] == 1){
                   grid[r-1][c] = 2;
                   q.push({r-1,c});
                   rotted=true;
                   fresh--;
                }
                if(r+1 < rows && grid[r+1][c] == 1){
                   grid[r+1][c] = 2;
                   q.push({r+1,c});
                   fresh--;
                   rotted=true;
                }
                if(c-1 >=0 && grid[r][c-1] == 1){
                   grid[r][c-1] = 2;
                   q.push({r,c-1});
                   fresh--;
                   rotted=true;
                }
                if(c+1 < cols && grid[r][c+1] == 1){
                   grid[r][c+1] = 2;
                   q.push({r,c+1});
                   fresh--;
                   rotted=true;
                }
            }

            if(rotted){
                time++;
            }
            

        }

        if(fresh > 0){
            return -1;
        }

        return time;


        
    }
};