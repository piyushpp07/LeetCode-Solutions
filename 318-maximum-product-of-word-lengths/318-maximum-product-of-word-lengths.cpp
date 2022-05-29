class Solution
{
    private:
        bool hasCommon(string a, string b)
        {
            map<char, int> mp2;

            for (auto j: b)
                mp2[j]++;
            for (int i = 0; i < a.size(); i++)
            {
                if (mp2.find(a[i]) != mp2.end())
                    return true;
            }
            return false;
        }
    public:
        int maxProduct(vector<string> &words)
        {
            long long int ans = 0;
            int n = words.size();
            vector<vector < int>> count(n, vector<int> (26, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < words[i].size(); j++)
                {
                    count[i][words[i][j] - 'a'] = 1;
                }
            }

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int d = 1;
                    for (int k = 0; k < 26; k++)
                    {
                        if (count[i][k] == 1 && count[j][k] == 1)
                        {
                            d = 0;
                            break;
                        }
                    }
                    if (d == 1)
                    {
                        long long int cal = words[i].size() *words[j].size();
                        ans = max(ans, cal);
                    }
                }
            }
            return ans;
        }
};