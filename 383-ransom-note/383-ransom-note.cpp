class Solution
{
    public:
        bool canConstruct(string ransomNote, string magazine)
        {
            int a[26] = { 0 };
            int b[26] = { 0 };
            for (auto i: ransomNote)
                a[i - 'a']++;
            for (auto j: magazine)
                b[j - 'a']++;
            for (int i = 0; i < 26; i++)
            {
                if (a[i] > b[i])
                    return false;
            }
            return true;
        }
};