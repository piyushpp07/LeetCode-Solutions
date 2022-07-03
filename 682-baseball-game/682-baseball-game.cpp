class Solution
{
    public:
        int calPoints(vector<string> &ops)
        {
            stack<int> st;
            for (string i: ops)
            {
                if (i == "C")
                {
                    st.pop();
                }
                else if (i == "D")
                {
                    int a = st.top();
                    st.push(a *2);
                }
                else if (i == "+")
                {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int ans = a + b;
                    st.push(b);
                    st.push(a);
                    st.push(ans);
                }
                else
                {
                    int a = stoi(i);
                    st.push(a);
                }
            }
            int ans = 0;
            while (st.size() != 0)
            {
                int a = st.top();
                st.pop();
                ans += a;
            }
            return ans;
        }
};