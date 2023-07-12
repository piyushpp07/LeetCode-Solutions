class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         vector<int> ans;
         queue<int>que;
         int n=graph.size();
        vector<int>adj[n];
        vector<int>outdegree(n);
         for(int i=0;i<n;i++){
             for(auto &itr:graph[i]){
                 adj[itr].push_back(i);
             }
             outdegree[i]=graph[i].size();
             if(outdegree[i]==0)que.push(i);
         }

        while(!que.empty()){
            int node= que.front();
            que.pop();
            ans.push_back(node);

            for(auto &itr:adj[node]){
                outdegree[itr]--;
                if(outdegree[itr]==0)que.push(itr);
            }

        }

        sort(ans.begin(),ans.end());
        return ans;
        
    }
};