class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> &words)
        {
            map<char, vector < string>> mp;
            for (char i: s)
                mp[i] = {};
            for (int i = 0; i < words.size(); i++)
            {
                if (mp.find(words[i][0]) != mp.end())
                {
                    mp[words[i][0]].push_back(words[i]);
                }
            }
            int cnt = 0;
            for (char ch: s)
            {
                vector<string> s = mp[ch];
                mp[ch] = {};
                for (auto i: s)
                {
                    if (i.size() == 1)
                        cnt++;
                    else
                    {
                        string p = i.substr(1, i.size() - 1);
                        char m = p[0];
                        mp[m].push_back(p);
                    }
                }
            }
            return cnt;
        }
};