class Solution
{
    public:
        int lastStoneWeight(vector<int> &stones)
        {
            priority_queue<int> pq;
            for (auto i: stones)
                pq.push(i);
            int ans = 0;
            while (pq.size() != 1)
            {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                if (a == b)
                {
                    pq.push(0);
                }
                else
                {
                    int z = max(a, b) - min(a, b);
                    pq.push(z);
                }
            }
            return pq.top();
        }
};