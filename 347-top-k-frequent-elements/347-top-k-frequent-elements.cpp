bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            map<int, int> mp;
            for (int i = 0; i < nums.size(); i++)
            {
                mp[nums[i]]++;
            }
            vector<pair<int, int>> mid;
            for (auto i: mp)
                mid.push_back(i);
            sort(mid.begin(), mid.end(), comp);
            int cnt = 0;
            vector<int> v;
            for (auto i:mid)
            {
                if (cnt == k)
                    break;
                else
                {
                    v.push_back(i.first);
                    cnt++;
                }
            }
            return v;
        }
};