class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string a = "";
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                
                st.push(a);
                a = "";
            }
            else {
                a += s[i];
            }
        }
        st.push(a);
        string ans = "";
        int n = st.size();
        while(st.size())
        {
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        ans = ans.substr(1);
        return ans;
    }
};