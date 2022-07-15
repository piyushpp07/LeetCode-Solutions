class Solution
{
    public:
        bool isIsomorphic(string s, string t)
        {
            map<char, char> mp, mp1;
            for (int i = 0; i < s.size(); i++)
            {
                if (mp[s[i]])
                {
                    if (t[i] != mp[s[i]])
                        return false;
                }
                if(mp1[t[i]])
                {
                      if(mp1[t[i]]!=s[i])
                              return false;
                }
                else mp[s[i]] = t[i], mp1[t[i]] = s[i];
            }
            return true;
        }
};