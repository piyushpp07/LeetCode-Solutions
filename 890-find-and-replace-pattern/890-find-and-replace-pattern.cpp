class Solution
{
    public:
        vector<string> findAndReplacePattern(vector<string> &words, string pattern)
        {
            vector<string> ans;

            for (int i = 0; i < words.size(); i++)
            {
                string q = words[i];
                bool flag = true;
                map<char, char> mp;
                for (int j = 0; j < pattern.size(); j++)
                {
                    if (mp.find(pattern[j]) == mp.end())
                        mp[pattern[j]] = q[j];

                    if (mp[pattern[j]] != q[j])
                    {   cout<<"at"<<j<<" ";
                        flag = false;
                        break;
                    }
                    for (auto r: mp)
                    {
                        if (r.second == q[j] && r.first != pattern[j])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    ans.push_back(q);
                }
            }
            return ans;
        }
};