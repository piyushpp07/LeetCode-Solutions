// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
   bool helper(int node, vector<int>adj[],int vis[],int dfsvis[])
   {
       vis[node]=1;
       dfsvis[node]=1;
       for(auto it : adj[node])
       {
           if(!vis[it])
           {
               if(helper(it,adj,vis,dfsvis)==true)
               return true;
           }
           else if(dfsvis[it]==true)
           return true;
       }
       dfsvis[node]=0;
       return false;
   }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
      int vis[V],dfsvis[V];
      memset(vis,0,sizeof vis);
      memset(dfsvis,0,sizeof dfsvis);
      for(int i=0;i<V;i++)
      {
          if(!vis[i])
          {
              if(helper(i,adj,vis,dfsvis)==true)
              return true;
          }
      }
      return false;
      
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends