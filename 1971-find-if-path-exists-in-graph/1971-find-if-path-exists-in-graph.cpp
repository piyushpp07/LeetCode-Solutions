class Solution {
private :
    bool dfs(int src ,int end ,vector<int>&vis , vector<vector<int>>&edges)
    {  
        if(src==end)
            return true;
        vis[src]=1;
        for(auto i : edges[src])
        {       if(!vis[i])
                if(dfs(i,end,vis,edges)==true)
                    return true;
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int>vis(n,0);
        vector<vector<int>>graph(n);
        for(auto i : edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
       
       return  dfs(start ,end ,vis , graph);

    }
};