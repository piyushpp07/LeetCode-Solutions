class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
            vector<string> v;
            string t = "";
            for (int i = 0; i < s.size(); i++)
            {

                if (s[i] == ' ' && t.size() == 0)
                    continue;
                else if (s[i] == ' ' && t.size() != 0)
                {
                    v.push_back(t);
                    t = "";
                }
                else
                {
                    t += s[i];
                }
            }
            if (t.size() != 0)
                v.push_back(t);
            return v[v.size() - 1].size();
        }
};