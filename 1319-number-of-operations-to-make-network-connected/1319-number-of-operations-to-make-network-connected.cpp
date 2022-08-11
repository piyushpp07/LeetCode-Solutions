bool comp(vector<int>&a,vector<int>&b)
{
    return a[0]<b[0];
}
class Solution
{
    public:
        int par[100001];
    int cc = 0;
    int find(int a)
    {
        if (a == par[a])
            return par[a];
        else
            return par[a] = find(par[a]);
    }
    void Union(int a, int b)
    {
        int l = find(a);
        int m = find(b);
        if(l!=m)
        {
            par[l] = m;
            cc++;
        }
    }
    int makeConnected(int n, vector<vector < int>> &connections)
    {
        memset(par, 0, sizeof par); 
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
        for (int i = 0; i < connections.size(); i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            Union(a,b);
        }
        return connections.size()<n-1?-1:(n-1)-cc;
        
    }
};