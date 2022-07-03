class Solution
{
    public:
        vector<int> finalPrices(vector<int> &arr)
        {
            stack<int> st;
            vector<int> v;
            int n = arr.size();
            for (int i = n - 1; i >= 0; i--)
            {
                if (st.size() == 0)
                    v.push_back(-1);
                else if (st.size() != 0 && st.top() <= arr[i])
                    v.push_back(st.top());
                else if (st.size() != 0 && st.top() > arr[i])
                {
                    while (st.size() > 0 && st.top() > arr[i])
                        st.pop();
                    if (st.size() == 0)
                        v.push_back(-1);
                    else
                        v.push_back(st.top());
                }
                st.push(arr[i]);
            }
            reverse(v.begin(), v.end());
            for (int i = 0; i < n; i++)
            {
                if (v[i] == -1) continue;
                else
                {
                    arr[i] = abs(arr[i] - v[i]);
                }
            }
            return arr;
        }
};