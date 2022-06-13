class Solution
{
    public:
        vector<string> findRepeatedDnaSequences(string s)
        {
            map<string, int> mp;
            if(s.size()<10)
                    return {};
            string s1 = s.substr(0, 10);
            mp[s1]++;
            int j = 0;
            while (j < s.size() - 10)
            {
                j++;
                string t = s.substr(j, 10 );
                mp[t]++;
            }
            vector<string> v;
            for (auto i: mp)
            {
                if (i.second >= 2)
                {
                    v.push_back(i.first);
                }
            }
            return v;
        }
};