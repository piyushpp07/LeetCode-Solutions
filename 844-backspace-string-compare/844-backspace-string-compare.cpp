class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        if(s[0]!='#')
        st1.push(s[0]);
        if(t[0]!='#')
        st2.push(t[0]);
        for(int i = 1;i<s.size();i++)
        {
                if(s[i]=='#')
                {
                  if(st1.size()!=0)
                          st1.pop();
                }
                else st1.push(s[i]);
        }
        for(int i =1;i<t.size();i++)
        {
                if(t[i]=='#')
                {
                  if(st2.size()!=0)
                          st2.pop();
                }
                else 
                        st2.push(t[i]);
        }
        if(st1.size()==0&&st2.size()==0)
                return true;
        else
        {
              if(st1.size()!=st2.size())
                      return false;
              else{
                      while(st1.size()!=0&&st2.size()!=0)
                      {
                              if(st1.top()!=st2.top())
                                      return false;
                              else{
                                      st1.pop();
                                      st2.pop();
                              }
                      }
                      return true;
              }

        }
            
            
    }
};