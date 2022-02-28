class Solution {
    private:
    bool is(stack<char>&st,char ch)
    {   if(st.size()==0)
        return 0;
        if(st.top()!=ch)
        return false;
        else{
            st.pop();
            return true;
        }
    }
    
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(int i = 0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch == '('||ch == '{'||ch == '[')
                st.push(ch);
            if(ch == ')')
            {
              bool s = is(st,'(');
              if(s == false)
              {
                  return false;
              }
            }
            if(ch == ']'){
                bool s = is(st,'[');
                if(s == false)
                    return false;
            }
            if(ch == '}')
            {
                bool s = is(st,'{');
                if(s== false)
                    return false;
            }

        }
        if(st.size()==0)
        return true;
        return false;
    }
};