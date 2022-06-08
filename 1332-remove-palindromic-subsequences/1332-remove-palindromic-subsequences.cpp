class Solution
{
  
    public:
        int removePalindromeSub(string s)
        {
            string t = s;
            reverse(s.begin(),s.end());
            return (t==s)?1:2;
        }
};