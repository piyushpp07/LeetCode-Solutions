bool comp(int a, int b)
{
    return a > b;
}
class Solution
{
    private:
        int find(int freq, vector<int> v, int idx)
        {
            for (int i = 0; i < 26; i++)
                if (freq == v[i] && idx != i)
                    return 1;
            return 0;
        }
    public:
        int minDeletions(string s)
        {
            int ans = 0;
            int n = s.size();
            vector<int> v(26, 0);
            for (auto i: s)
                v[i - 'a']++;
            sort(v.begin(), v.end(), comp);
            for (int i = 0; i < 26; i++)
            {
                int cnt = 0;
                int freq = v[i];
                while (find(freq, v, i) && freq != 0)
                    freq--, cnt++;
                v[i] = freq;
                ans += cnt;
            }
            return ans;
        }
};