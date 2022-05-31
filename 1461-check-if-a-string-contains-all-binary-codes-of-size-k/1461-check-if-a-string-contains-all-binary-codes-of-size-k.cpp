class Solution
{
    public:
        bool hasAllCodes(string s, int k)
        {   if(s.size()<k)
                return false;
            int till = 1 << k;
            unordered_set<int> set;
            for (int i = 0; i < s.size() - k + 1; i++)
            {
                string str = s.substr(i, k);
                unsigned long long value = stoull(str, NULL, 2);
                set.insert(value);
            }
            return set.size() == till;
        }
};