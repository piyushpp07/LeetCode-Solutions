class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int ans = 0, l = 0, curr_len = 0;
            set<char> st;
            for (auto i: s)
            {
                while (st.find(i) != st.end())
                {
                    curr_len -= 1;
                    st.erase(s[l]);
                    l++;
                }
                st.insert(i);
                curr_len += 1;
                ans = max(curr_len, ans);
            }

            return ans;
        }
};