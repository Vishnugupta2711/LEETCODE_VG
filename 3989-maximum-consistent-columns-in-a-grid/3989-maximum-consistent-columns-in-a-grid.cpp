class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m,1);
        for(int i = 0;i<m;i++){
            for(int j = 0 ;j<i;j++){
                bool ok = true;
                for(int r = 0;r<n;r++){
                    if(abs(grid[r][i] - grid[r][j]) > limit){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};