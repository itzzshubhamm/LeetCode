class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col,
             vector<vector<bool>>& Ocean) {
        int rows = heights.size();
        int cols = heights[0].size();
        if (row < 0 || col < 0) {
            return;
        }
        if (row >= rows || col >= cols) {
            return;
        }

        if(Ocean[row][col]){
            return;
        }

        Ocean[row][col] = true;

        vector<vector<int>> direction =
        { {-1, 0},
          {1, 0},
          {0, -1},
          {0, 1} };

        for (auto dir : direction) {
            int nr = row + dir[0];
            int nc = col + dir[1];

            if (nr < 0 || nc < 0) {
                continue;
            }
            if (nr >= rows || nc >= cols) {
                continue;
            }

            if(heights[nr][nc] < heights[row][col]){
             continue;
            }

            dfs(heights, nr, nc, Ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacificOcean(rows, vector<bool>(cols , false));
        vector<vector<bool>> atlanticOcean(rows, vector<bool>(cols , false));
        vector<vector<int>> result;

        for (int i = 0; i < cols; i++) {
            dfs(heights, 0, i, pacificOcean);
        }
        for (int i = 0; i < rows; i++) {
            dfs(heights, i, 0, pacificOcean);
        }

        for (int i = 0; i < cols; i++) {
            dfs(heights, rows - 1, i, atlanticOcean);
        }
        for (int i = 0; i < rows; i++) {
            dfs(heights, i, cols - 1, atlanticOcean);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacificOcean[i][j] && atlanticOcean[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};