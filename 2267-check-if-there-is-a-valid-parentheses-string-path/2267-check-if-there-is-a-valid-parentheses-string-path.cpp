class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // A valid parentheses string must have even length.
        if (len % 2 != 0)
            return false;

        // Balance can never exceed len.
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= len; balance++) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance - 1;
                    else
                        newBalance = balance + 1;

                    if (newBalance < 0 || newBalance > len)
                        continue;

                    // Come from top
                    if (i > 0 && dp[i - 1][j][newBalance])
                        dp[i][j][balance] = true;

                    // Come from left
                    if (j > 0 && dp[i][j - 1][newBalance])
                        dp[i][j][balance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};