class Solution
{
    private:
        set<vector<int>>s;
    void solve(map<int, int> &mp, int n, vector<int> &v, int d)
    {
        if (v.size() == n)
        {
            s.insert(v);
        }
        if (mp.size() == 0)
            return;
        if (d >= n)
            return;
        for (auto i: mp)
        {   int q = i.first;
            for (int j = 0; j < i.second; j++)
            {        
                mp[q]--;
                v.push_back(q);
                solve(mp, n, v, d + 1);
                v.pop_back();
                mp[q]++;
            }
        }
    }

    public:
        vector<vector < int>> permuteUnique(vector<int> &nums)
        {
            map<int, int> mp;
            for (int i: nums)
                mp[i]++;
            int n = nums.size();
            vector<int> v;
            solve(mp, n, v, 0);
            vector<vector<int>>ref;
            for(auto i : s)
                    ref.push_back(i);
            return ref;
        }
};