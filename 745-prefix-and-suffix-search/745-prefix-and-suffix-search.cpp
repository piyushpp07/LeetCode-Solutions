class WordFilter
{
    unordered_map<string, int> mp;
    public:
        WordFilter(vector<string> &words)
        {
            for (int w = 0; w < words.size(); w++)
            {
                string s = words[w];

                for (int i = 1; i <= s.size(); i++)
                {
                    string pre = s.substr(0, i);
                    for (int j = 0; j < s.size(); j++)
                    {
                        string suff = s.substr(j);
                        string z = pre + "#" + suff;
                        mp[z] = w;
                    }
                }
            }
        }

    int f(string prefix, string suffix)
    {
        string s = prefix + "#" + suffix;
        if (mp.find(s) == mp.end())
            return -1;
        else return mp[s];
    }
};

/**
 *Your WordFilter object will be instantiated and called as such:
 *WordFilter* obj = new WordFilter(words);
 *int param_1 = obj->f(prefix,suffix);
 */