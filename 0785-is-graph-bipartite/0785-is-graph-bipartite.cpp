class Solution {
public:
    bool checkBipartiteDfs(int node, vector<int> adj[], vector<int> &color){
        if(color[node] == -1) color[node] =1;
        for(auto x : adj[node]){
            if(color[x] == -1){
                color[x] = 1 - color[node];
                if(!checkBipartiteDfs(x, adj, color)){
                    return false;
                }
            }
            else if(color[x] == color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            for(auto x : graph[i]){
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!checkBipartiteDfs(i,adj,color)){
                    return false;
                }
            }
        }
        return true;
        
    }
};