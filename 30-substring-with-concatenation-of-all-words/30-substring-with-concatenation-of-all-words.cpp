class Solution
{
    public:
        bool check(unordered_map<string, int> mp, string s, int n)
        {
            int i = 0;
            while (i < s.size())
            {
                string q = s.substr(i, n);
                if (mp.find(q) == mp.end())
                    return false;
                else
                {
                    if (--mp[q] == -1)
                        return false;
                }
                i+=n;
            }
            return true;
        }
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = words[0].size();
        int fixed = n *words.size();
        vector<int> ans;
        unordered_map<string, int> mp;
        for (auto i: words)
            mp[i]++;
        int i = 0;
        while (i + fixed <= s.size())
        {
            if (check(mp, s.substr(i, fixed), n))
                ans.push_back(i++);
            else i++;
        }
        return ans;
    }
};