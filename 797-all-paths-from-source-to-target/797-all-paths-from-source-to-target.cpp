class Solution {
private:
vector<vector<int>>ans;
void dfs(int src , int end , vector<vector<int>>&graph,vector<int>&vis,vector<int>&a)
{   
    if(src==end)
    {  a.push_back(src);
        ans.push_back(a);
       a.pop_back();
    }
    a.push_back(src);
    for(auto i : graph[src])
            dfs(i,end,graph,vis,a);
    a.pop_back();
    
}
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>a;
        int n= graph.size();
        vector<int>vis(n,0);
        dfs(0,n-1,graph,vis,a);
        return ans;
    }
};