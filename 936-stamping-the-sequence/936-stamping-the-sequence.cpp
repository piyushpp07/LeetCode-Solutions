class Solution
{
    public:
        int count = 0;
    bool match(string &x, string &y)
    {
        for (int i = 0; i < x.size(); i++)
        {
            if (y[i] != '?' && x[i] != y[i]) return false;
        }
        return true;
    }
    void change(string &target, int id, int m)
    {
        for (int i = id; i < id + m; i++)
        {
            if (target[i] != '?')
            {
                count++;
                target[i] = '?';
            }
        }
    }
    vector<int> movesToStamp(string stamp, string target)
    {
        int n = target.size();
        int m = stamp.size();
        stack<int> st;
        vector<int> vis(target.size(), 0);
        while (count != n)
        {
            int f = 0;
            for (int i = 0; i < n; i++)
            {
                string temp = target.substr(i, m);
                if (!vis[i] && match(stamp, temp))
                {
                    f = 1;
                    st.push(i);
                    change(target, i, m);
                    vis[i] = 1;
                }
            }
            if (!f) return {};
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};