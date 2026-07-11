class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        if(source == target){
            return {0LL,(long long)power};
        }
        vector<vector<pair<int,int>>> g(n);
        for(auto &e :edges){
            g[e[0]].push_back({e[1],e[2]});
        }
        const long long INF = 4e18;
        vector<vector<long long>>dist(n , vector<long long>(power+1,INF));
        priority_queue<tuple<long long ,int ,int>,vector<tuple<long long ,int,int>>,greater<tuple<long long ,int,int>>>pq;
        dist[source][power] =0 ;
        pq.push({0,source,power});
        while(!pq.empty()){
            auto [t,u,p] = pq.top();
            pq.pop();
            if(t != dist[u][p])continue;
            if(p<cost[u])continue;
            int np = p - cost[u];
            for(auto &[v,w] :g[u]){
                long long nt = t+w;
                if(nt < dist[v][np]){
                    dist[v][np] = nt ;
                    pq.push({nt,v,np});
                }
            }
        }
        long long best = INF;
        int bestpow = -1;
        for(int p = 0 ; p <=power ;p++){
            if(dist[target][p] < best){
                best = dist[target][p];
                bestpow = p;
                
            }
            else if(dist[target][p] == best){
                bestpow = max(bestpow,p);
            }
            
        }
        if(best == INF) return {-1,-1};
        return {best,(long long)bestpow};
    }
    
};