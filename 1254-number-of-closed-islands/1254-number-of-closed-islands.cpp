class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dirs[5] = {-1, 0, 1, 0, -1};

        function<bool(int, int)> dfs = [&](int r, int c) -> bool {
            if (r < 0 || r >= m || c < 0 || c >= n)
                return false;

            if (grid[r][c] == 1)
                return true;

            grid[r][c] = 1;
            bool closed = true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k];
                int nc = c + dirs[k + 1];

                if (!dfs(nr, nc))
                    closed = false;
            }

            return closed;
        };

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && dfs(i, j))
                    ans++;
            }
        }

        return ans;
    }
};