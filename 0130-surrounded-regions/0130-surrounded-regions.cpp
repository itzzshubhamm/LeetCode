class Solution {
public:

    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void dfs(int row, int col, vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        if(row < 0 || row >= rows ||
           col < 0 || col >= cols)
            return;

        if(board[row][col] != 'O')
            return;

        // Mark this O as safe
        board[row][col] = 'S';

        for(auto dir : directions) {

            int newRow = row + dir[0];
            int newCol = col + dir[1];

            dfs(newRow, newCol, board);
        }
    }

    void solve(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        // Top and bottom boundaries
        for(int col = 0; col < cols; col++) {

            if(board[0][col] == 'O')
                dfs(0, col, board);

            if(board[rows - 1][col] == 'O')
                dfs(rows - 1, col, board);
        }

        // Left and right boundaries
        for(int row = 0; row < rows; row++) {

            if(board[row][0] == 'O')
                dfs(row, 0, board);

            if(board[row][cols - 1] == 'O')
                dfs(row, cols - 1, board);
        }

        // Capture surrounded regions
        for(int row = 0; row < rows; row++) {

            for(int col = 0; col < cols; col++) {

                if(board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
                else if(board[row][col] == 'S') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};