class Solution
{
    private:
        vector<vector < int>> ans;
    void solve(map<int, int> &mp, int n, vector<int> &v, int d)
    {
        if (v.size() == n)
        {
            ans.push_back(v);
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
            set<vector<int>>s;
            for(auto i : ans)
            {
                    s.insert(i);
            }
            vector<vector<int>>ref;
            for(auto i : s)
                    ref.push_back(i);
            return ref;
        }
};