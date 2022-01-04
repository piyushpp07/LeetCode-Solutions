class Solution {
private:
    bool isbp(int col[],vector<vector<int>> &graph,int i)
    {
        if(col[i]==-1)
            col[i]=1;
        for(auto it : graph[i])
        {
           if(col[it]==-1)
           {
               col[it]=1-col[i];
               if(isbp(col,graph,it)==false)
                   return false;
          //recursive dfs call
           }
           if(col[it]==col[i])
               return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        int col[V+1];
        memset(col,-1,sizeof(col));
        for(int i=0;i<V;i++)
        {
            if(col[i]==-1)
            {
                if(isbp(col,graph,i)==false)
                    return false;
            }
        }
        return true;
    }
};