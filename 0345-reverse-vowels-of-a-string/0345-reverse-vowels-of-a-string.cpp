class Solution {
public:
    string reverseVowels(string s) {
        stack<char>st;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i] =='u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                st.push(s[i]);
        }
        string a = "";
        for(int i = 0;i<s.size();i++)
        {
         if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i] =='u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                a += st.top();
                st.pop();
            }
            else{
                a += s[i];
            }
        }
        return a;
    }
};