class Solution {
private:
    bool isbp(int col[],vector<vector<int>>& graph,int i)
    {
        queue<int>q;
        q.push(i);
        col[i]=1;
        while(q.size()>0)
        {
            int a=q.front();
            q.pop();
            for(int m:graph[a])
            {
                if(col[m]==-1)
                {
                    col[m]=1-col[a];
                    q.push(m);
                }
                else if(col[m]==col[a])
                {
                    return false;
                }
            }
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