class Solution {
private:
    void bfs(int i , int j , vector<vector<char>>& board, vector<vector<int>>& visited){
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        int delrow[4]= {-1,0,1,0};
        int delcol[4]= {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            for(int k = 0; k < 4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    if(board[nrow][ncol] == 'O' && !visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m ,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) 
                    && board[i][j] == 'O' && !visited[i][j]){
                    bfs(i , j , board , visited);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && visited[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};