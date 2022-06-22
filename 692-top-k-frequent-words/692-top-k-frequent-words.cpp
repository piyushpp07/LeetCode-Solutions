bool comp(pair<string, int> &a, pair<string, int> &b)
{   if(a.second != b.second)
    return a.second > b.second;
    else return a.first<b.first;
}
class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            map<string, int> mp;
            for (auto i: words)
            {
                mp[i]++;
            }
            vector<pair<string, int>> mid;
            for (auto i: mp)
            {
                mid.push_back(i);
            }
            sort(mid.begin(), mid.end(), comp);
            int cnt = 0;
            vector<string> ans;
            for (auto i: mid)
            {
                if (cnt == k)
                    break;
                else
                {
                    ans.push_back(i.first);
                        cnt++;
                }
            }
            return ans;
        }
};