class Solution
{
    public:
        int par[100001];
    int s[100001];
    int cc = 0;
    void make(int i)
    {
        par[i] = i;
        s[i] = 1;
    }
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
        if (l!=m)
        {
            if (s[l] < s[m])
                swap(l, m);
            par[m] = l;
            s[l] += s[m];
            cc++;
        }
    }
    int makeConnected(int n, vector<vector < int>> &connections)
    {
        memset(par, 0, sizeof par);
        memset(s, 0, sizeof s);
        for (int i = 0; i < n; i++)
        {
            make(i + 1);
        }
        for (int i = 0; i < connections.size(); i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            Union(a + 1, b + 1);
        }
        return connections.size()<(n-1)?-1:(n-1)-cc;
    }
};