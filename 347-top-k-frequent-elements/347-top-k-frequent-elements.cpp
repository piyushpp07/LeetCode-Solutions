class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            using ppi = pair<int, int> ;
            priority_queue<ppi, vector < ppi>, greater < ppi>> pq;
            map<int, int> mp;
            for (int i = 0; i < nums.size(); i++)
            {
                mp[nums[i]]++;
            }
            for (auto i: mp)
            {
                pq.push({ i.second,
                    i.first });
                if (pq.size() > k)
                    pq.pop();
            }
            vector<int> v;
            while (!pq.empty())
            {
                auto a = pq.top();
                v.push_back(a.second);
                pq.pop();
            }
            return v;
        }
};