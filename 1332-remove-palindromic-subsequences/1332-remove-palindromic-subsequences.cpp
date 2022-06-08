class Solution
{
  
    public:
        int removePalindromeSub(string s)
        {
            string t = s;
            reverse(s.begin(),s.end());
            if(t == s)
                    return 1;
            return 2;
        }
};