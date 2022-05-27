class Solution
{
    vector<int> v;
    private:
        void dfs(int i, int n)
        {
            if (i > n)
                return;
            v.push_back(i);
            for (int j = 0; j < 10; j++)
            {
                dfs(10*i+j, n);
            }
        }
    public:
        vector<int> lexicalOrder(int n)
        {
            for (int i = 1; i < 10; i++)
            {
                dfs(i, n);
            }
            return v;
        }
};