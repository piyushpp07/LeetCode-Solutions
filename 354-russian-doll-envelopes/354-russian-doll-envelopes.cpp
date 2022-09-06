bool comp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[0] > b[0];
    else return a[1] < b[1];
}
class Solution
{
    public:
        int maxEnvelopes(vector<vector < int>> &env)
        {
            sort(env.begin(), env.end(), comp);
            vector<int>lis;
            for (auto i: env)
            {
                int ele = i[0];

                int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();

                if (idx >= lis.size()) lis.push_back(ele);
                else lis[idx] = ele;
            }
            return lis.size();
        }
};