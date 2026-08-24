class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {

        if (row < 0 || row >= grid.size()) {
            return 0;
        }

        if (col < 0 || col >= grid[0].size()) {
            return 0;
        }

        if (grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0;

        return 1 + dfs(grid, row - 1, col) +
               dfs(grid, row + 1, col) + dfs(grid, row, col + 1) +
               dfs(grid, row, col - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;
        int rowSize = grid.size();
        int colSize = grid[0].size();

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};