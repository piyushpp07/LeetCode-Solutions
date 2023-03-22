class dsu{
    public:
        vector<int> parent;
        vector<int> size;
        dsu(int n)
        {
            parent.assign(n,-1);
            size.assign(n,0);
        }
        void make_set(int v)
        {
            parent[v]=v;
            size[v]=1;
        }
        int find_parent(int v)
        {
            if(v==parent[v])    return v;
            return parent[v]=find_parent(parent[v]);
        }
        void union_set(int x,int y)
        {
            x=find_parent(x);
            y=find_parent(y);
            if(x!=y)
            {
                if(size[x]<size[y]) swap(x,y);
                parent[y]=x;
                size[x]+=size[y];
            }
        }
};
class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        dsu _dsu(n+1);
        for(int i =1;i<=n;i++)
            _dsu.make_set(i);
        int ans = INT_MAX;
        vector<pair<int,int>>v;
        for(int i =0;i<roads.size();i++)
        {
            int x = roads[i][0];
            int y = roads[i][1];
            int cost = roads[i][2];
            v.push_back({x,y});
            _dsu.union_set(x,y);
        }
        int par1 = _dsu.find_parent(1);
              for(int i =0;i<roads.size();i++)
        {
            int x = roads[i][0];
            int y = roads[i][1];
            int cost = roads[i][2];
            if(_dsu.find_parent(x) == par1)
            {
                ans = min(ans,cost);
            }
        }
        return ans;
    }
};