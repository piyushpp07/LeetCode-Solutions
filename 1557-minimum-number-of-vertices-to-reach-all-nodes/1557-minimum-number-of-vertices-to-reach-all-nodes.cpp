class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       vector<int>indegree(n,0);
       for(auto i : edges)
       {
           indegree[i[1]]++;
       }
       vector<int>a;
       for(int i=0;i<n;i++)
       {
           if(indegree[i]==0)
               a.push_back(i);
       }
       return a;
    }
};