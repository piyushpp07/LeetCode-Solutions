bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
class Solution
{

    public:
        vector<int> frequencySort(vector<int> &nums)
        {
            map<int, int> mp;
            for (auto i: nums)
                mp[i]++;
            vector<pair<int, int>> v;
            for (auto i: mp)
                v.push_back({ i.second,
                    i.first });
            sort(v.begin(), v.end(), comp);
            vector<int> ans;
            for (auto i: v)
            {
                int times = i.first;
                while (times)
                {
                    ans.push_back(i.second);
                    times--;
                }
            }

            return ans;
        }
};