class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& grid) {

        grid[row][col] = '0';

        int directions[4][2] = {
            {-1, 0},  // up
            {1, 0},   // down
            {0, -1},  // left
            {0, 1}    // right
        };

        for(auto& dir : directions) {

            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if(newRow >= 0 && newRow < grid.size() &&
               newCol >= 0 && newCol < grid[0].size() &&
               grid[newRow][newCol] == '1') {

                dfs(newRow, newCol, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        for(int i = 0; i < grid.size(); i++) {

            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == '1') {

                    count++;

                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};