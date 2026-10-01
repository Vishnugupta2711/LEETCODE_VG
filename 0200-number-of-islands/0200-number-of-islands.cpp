class Solution {
public:
    void bfs(int row , int col , vector<vector<char>>& grid,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(int i = 0;i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1' && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i = 0 ;i<m;i++){
            for(int j= 0 ;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cnt++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};