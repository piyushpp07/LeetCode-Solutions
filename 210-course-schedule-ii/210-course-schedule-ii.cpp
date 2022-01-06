class Solution {
private :
   void dfs(vector<vector<int>>&graph,int src, int vis[],stack<int>&st)
   {
       vis[src]=1;
       for(auto it : graph[src])
       {
           if(!vis[it])
           {
               dfs(graph,it,vis,st);
           }
       }
       st.push(src);
   }
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {

        vector<vector<int>>graph(N);
        vector<int>topo;
        int in[N];
        memset(in,0,sizeof in);
        for(auto it : pre)
        {
            graph[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
//         stack<int>st;
//         int vis[numCourses];
//         memset(vis,0,sizeof vis);
//         for(int i=0;i<n;i++)
//         {
//             if(!vis[i])
//             {
//                 dfs(graph,i,vis,st);
//             }
//         }
//         vector<int>topo;
//         while(!st.empty())
//         {
//             topo.push_back(st.top());
//             st.pop();
            
//         }
//         return topo;
          queue<int>q;
          for(int i=0;i<N;i++)
          {
              if(in[i]==0)
                  q.push(i);
          }
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
              topo.push_back(node);
              for(auto it : graph[node])
              {
                  in[it]--;
                  if(in[it]==0)
                  q.push(it);
              }
          }
           if(size(topo) ==N) return topo; 
        return {};

    }
};