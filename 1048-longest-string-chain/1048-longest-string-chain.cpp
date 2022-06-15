bool comp(string s1, string s2)
{
    return s1.size() < s2.size();
}
class Solution
{
    int dp[1001];
    bool isPre(string &s, string &t)
    {
        int start = 0, j = 0, cnt = 0;
        if (t.size() != s.size() + 1) return false;
        else
        {
            for (int i = 0; i < t.size(); i++)
            {
                if (start == 0)
                {
                    if (t[i] == s[j])
                        cnt++, j++, start = 1;
                }
                else if (start == 1)
                {
                    if (t[i] == s[j])
                        cnt++, j++;
                }
            }
        }
        return s.size() == cnt;
    }
    int solve(int idx, vector<string> &words)
    {
        if (idx == words.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        else
        {
            int ans = 0;
            for (int j = idx + 1; j < words.size(); j++)
            {
                if (isPre(words[idx], words[j]))
                {
                    ans = max(ans, 1 + solve(j, words));
                }
            }
            return dp[idx] = ans;
        }
    }
    public:
        int longestStrChain(vector<string> &words)
        {
            memset(dp, -1, sizeof dp);
            int ans = 0, n = words.size();
            sort(words.begin(), words.end(), comp);
            for (int i = 0; i < n; i++)
            {
                int mans = solve(i, words);
                if (mans > ans)
                    ans = mans;
            }
            return 1 + ans;
        }
};