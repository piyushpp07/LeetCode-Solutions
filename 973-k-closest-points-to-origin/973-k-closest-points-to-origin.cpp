using piii = pair<int, pair<int, int>> ;
using lli = long long int;
class Solution
{
    public:
        vector<vector < int>> kClosest(vector<vector < int>> &points, int k)
        {
            priority_queue<piii> pq;
            for (auto i: points)
            {
                lli x = i[0];
                lli y = i[1];
                lli d = x *x + y * y;
                pq.push({ d,
                    {
                        x,
                        y
                    } });
                if (pq.size() > k)
                    pq.pop();
            }
            vector<vector < int>> ans;
            while (!pq.empty())
            {
                vector<int> p;
                auto a = pq.top();
                int x = a.second.first;
                int y = a.second.second;
                p.push_back(x);
                p.push_back(y);
                ans.push_back(p);
                pq.pop();
            }
            return ans;
        }
};