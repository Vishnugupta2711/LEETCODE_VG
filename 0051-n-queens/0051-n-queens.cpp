class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row, int n, vector<string>& board,vector<int>& col,vector<int>& diagonal1,vector<int>& diagonal2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {


            if (col[c]) continue;


            if (diagonal1[row - c + n - 1]) continue;


            if (diagonal2[row + c]) continue;


            board[row][c] = 'Q';
            col[c] = 1;
            diagonal1[row - c + n - 1] = 1;
            diagonal2[row + c] = 1;

            solve(row + 1, n, board, col, diagonal1, diagonal2);


            board[row][c] = '.';
            col[c] = 0;
            diagonal1[row - c + n - 1] = 0;
            diagonal2[row + c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);


        vector<int> diagonal1(2 * n - 1, 0);


        vector<int> diagonal2(2 * n - 1, 0);

        solve(0, n, board, col, diagonal1, diagonal2);

        return ans;
    }
};