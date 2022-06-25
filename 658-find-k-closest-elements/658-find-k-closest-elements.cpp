class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            vector<int> ans;
            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < arr.size(); i++)
            {
                int a = abs(arr[i] - x);
                pq.push({ a,
                    arr[i] });
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
            while (!pq.empty())
            {
                auto a = pq.top();
                pq.pop();
                ans.push_back(a.second);
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
};