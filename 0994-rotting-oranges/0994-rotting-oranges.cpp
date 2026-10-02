class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        int freshcnt = 0;
        for(int i= 0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    freshcnt++;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;
            time = max(time,t);
            for(int i = 0;i<4 ;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr >= 0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == 1 && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({{nr,nc},t + 1});
                    freshcnt--;
                }
            }
        }
        if(freshcnt > 0){
            return -1;
        }
        else{
            return time;
        }
    }
};