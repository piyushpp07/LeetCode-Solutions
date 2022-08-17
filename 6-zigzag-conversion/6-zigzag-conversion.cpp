class Solution
{
    public:
        string convert(string s, int numRows)
        {
        
            map<int, string> mp;
            int lvl = 0;
            int down = 1;
            for (int i = 0; i < s.size(); i++)
            {
                if (lvl <= numRows && down)
                    mp[lvl++] += s[i];
                else if (!down && lvl >= 0)
                    mp[lvl--] += s[i];
                if (lvl == 0)
                {
                    lvl = 0;
                    down = 1;
                }
                else if (lvl == numRows-1)
                {
                    down = 0;
                    lvl = numRows - 1;
                }
            }

            string ans = "";
            for (auto i: mp)
            {
                ans += i.second;
            }
            return numRows == 1 ? s: ans;   
        }
};