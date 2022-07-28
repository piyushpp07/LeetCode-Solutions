class Solution
{
    public:
        string decodeString(string s)
        {
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != ']')
                {
                    st.push(s[i]);
                }
                else
                {
                    string str = "";
                    while (st.top() != '[')	//pop till the "["
                    {
                        str = st.top() + str;
                        st.pop();
                    }
                    st.pop();	//pop the "["

                    string k = "";	//finding the number before the "[]"

                    while (st.size() > 0 && isdigit(st.top()))
                    {
                        k = st.top() + k; //st top consist number 
                        st.pop();
                    }
                    int no = stoi(k);	// added the string no of times in the stack
                    for (int i = 0; i < no; i++)
                    {
                        for(int k = 0;k<str.size();k++)
                        {
                            st.push(str[k]);
                        }
                    }
                }
            }
            string ans = "";
            while (st.size() != 0)
            {
                ans = st.top() + ans;
                st.pop();
            }
            return ans;
        }
};