using lli = long long int;

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
                size[y] = 0;
            }
        }
};

class Solution {
public:
   
    long long countPairs(int n, vector<vector<int>>& edges) {
        dsu _dsu(n);
        for(int i = 0;i<n;i++)
        {
            _dsu.make_set(i);
        }
        for(auto i : edges)
        {
            int x = i[0];
            int y = i[1];
            _dsu.union_set(x,y);
        }
        lli ans = 0,tot = 0;
        for(auto i : _dsu.size )
        {
            tot += i;
        }
        for(auto i : _dsu.size )
        {
            if(i>0)
            ans += (tot - i)*(i);
        }
        return ans/2;
    }
    
};