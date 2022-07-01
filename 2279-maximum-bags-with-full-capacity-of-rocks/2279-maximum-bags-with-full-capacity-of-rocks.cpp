using pii = pair<int, int> ;
bool comp(pii a, pii b)
{
    int x = a.first - a.second;
    int y = b.first - b.second;
    return x < y;
}

class Solution
{
    public:
        int maximumBags(vector<int> &capacity, vector<int> &rocks, int rem)
        {
            vector<pii> a;
            for (int i = 0; i < capacity.size(); i++)
            {
                a.push_back({ capacity[i],
                    rocks[i] });
            }
            sort(a.begin(), a.end(), comp);
            int cnt = 0;
            for (int i = 0; i < a.size(); i++)
            {
                int req = a[i].first - a[i].second;
                if (req <= rem)
                {
                    cnt++;
                    rem = rem - req;
                }
                else
                {
                    break;
                }
            }
            return cnt;
        }
};