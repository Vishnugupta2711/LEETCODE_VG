class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for(int i = 0 ;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(topo.size() == n ){
            return topo;
        }
        return {};
    }
};