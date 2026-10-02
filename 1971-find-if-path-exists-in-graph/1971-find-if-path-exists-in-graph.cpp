class Solution {
public:
    bool dfs(int source ,int destination ,vector<vector<int>>& adjlt,vector<int>& visited){
        if(source == destination){
            return true;
        }
        visited[source] = 1;
        for(auto it : adjlt[source]){
            if(!visited[it]){
                if(dfs(it,destination,adjlt,visited)){
                    return true;
                }
            }
        }
        return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjlt(n);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            adjlt[u].push_back(v);
            adjlt[v].push_back(u);
        }
        vector<int> visited(n,0);
        return dfs(source , destination , adjlt ,visited);
    }
};