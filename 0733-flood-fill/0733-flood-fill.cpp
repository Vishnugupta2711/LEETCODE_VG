class Solution {
public:
    void bfs(int sr,int sc, vector<vector<int>>& image,int inicolor,int color,vector<vector<int>>& ans){
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        ans[sr][sc] = color;
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(int i = 0 ; i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == inicolor && ans[nr][nc] != color){
                    ans[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        if(inicolor == color){
            return ans;
        }
        bfs(sr,sc,image,inicolor,color,ans);
        return ans;
    }
};