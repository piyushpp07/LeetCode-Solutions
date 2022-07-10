class Solution
{
    private:
        int mah(vector<int> &nums)
        {
            stack<int> st;
            int n = nums.size();
            vector<int> ns, ps;
            for (int i = 0; i < nums.size(); i++)
            {
                if (st.size() == 0)
                    ps.push_back(-1);
                else if (st.size() > 0 && nums[i] > nums[st.top()])
                    ps.push_back(st.top());
                else if (st.size() > 0 && nums[i] <= nums[st.top()])
                {
                    while (st.size() > 0 && nums[i] <= nums[st.top()])
                        st.pop();
                    if (st.size() == 0)
                        ps.push_back(-1);
                    else
                        ps.push_back(st.top());
                }
                st.push(i);
            }
            while (!st.empty())
                st.pop();
            for (int i = n - 1; i >= 0; i--)
            {
                if (st.size() == 0)
                    ns.push_back(n);
                else if (st.size() > 0 && nums[i] > nums[st.top()])
                    ns.push_back(st.top());
                else if (st.size() > 0 && nums[i] <= nums[st.top()])
                {
                    while (st.size() > 0 && nums[i] <= nums[st.top()])
                        st.pop();
                    if (st.size() == 0)
                        ns.push_back(n);
                    else
                        ns.push_back(st.top());
                }
                st.push(i);
            }
            reverse(ns.begin(), ns.end());
            long long ans = 0;

            for (int i = 0; i < n; i++)
            {
                long long len = ns[i] - ps[i] - 1;
                ans = max(ans, len *nums[i]);
            }
            return ans;
        }
    public:
        int maximalRectangle(vector<vector < char>> &matrix)
        {
            int ans = 0;
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int> v(m, 0);
            for (int i = 0; i < m; i++)
            {
                if (matrix[0][i] == '1')
                    v[i] = 1;
                else continue;
            }
            ans = max(ans, mah(v));
            for (int i = 1; i < n; i++)
            {
                int k = 0;
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == '1')
                    {
                        v[j]++;
                    }
                    else
                        v[j] = 0;
                }
                ans = max(ans, mah(v));
            }
            for (int i = 0; i < m; i++)
            {
                cout << v[i] << " ";
            }
            return ans;
        }
};