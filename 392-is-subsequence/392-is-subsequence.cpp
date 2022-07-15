class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            if(s.size()==0)
                    return true;
            bool ans = true;
            int i = 0,j = 0;
            int n = s.size(), m = t.size();
            int cnt = 0;
            while (i < n && j < m)
            {
                if (s[i] == t[j])
                    i++, j++, cnt++;
                else if (s[i] != t[j]) j++;
                if (cnt == n)
                    return true;
            }
            return false;
        }
};