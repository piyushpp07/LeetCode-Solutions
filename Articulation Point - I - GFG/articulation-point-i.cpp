//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer = 0;
  void dfs(int node,int par,vector<int>&mark,vector<int>&vis,int low[],int tin[],vector<int>adj[])
  {
      vis[node] = 1;
      int child = 0;
      tin[node] = low[node] = timer;
      timer++;
      for(auto i : adj[node])
      {
          if(par == i)
          continue;
          if(!vis[i])
          {
              dfs(i,node,mark,vis,low,tin,adj);
              low[node] = min(low[node],low[i]);
              if(tin[node]<=low[i] and par!=-1)
              {
                  mark[node] = 1;
              }
              child++;
          }
          else
          {
              low[node] = min(tin[i],low[node]);
          }
      }
      if(child > 1 and par == -1)
      mark[node] = 1;
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>vis(V,0);
        int tin[V];
        int low[V];
        vector<int>mark(V,0);
        for(int i = 0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                dfs(i,-1,mark,vis,low,tin,adj);
            }
        }
        vector<int>ans;
        for(int i = 0;i<V;i++)
        {
            if(mark[i])
            ans.push_back(i);
        }
        if(ans.size() ==0)
        return {-1};
        else 
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends