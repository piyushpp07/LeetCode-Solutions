class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int , int>mp;
        int n= edges.size();
        for(int i=0;i<n;i++)
        {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        int ans=0;
        for(auto m:mp)
        {
            if(m.second==n)
            {
                ans = m.first;
            }
        }
        return ans;
    }
};