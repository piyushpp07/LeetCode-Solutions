bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] > b[0];
    return a[1] < b[1];
}
class Solution
{
    public:

    int numberOfWeakCharacters(vector<vector < int>> &prop)
    {
        sort(prop.begin(), prop.end(), comp);
        int maxTillNow = INT_MIN;
        int ans = 0;
        for (auto p: prop)
        {
            if (maxTillNow > p[1]) ans++;
            else maxTillNow = p[1];
        }
        return ans;
    }
};
// remember when we have given about two d array and sorting kind of que sort in opp dixn fom 0 and 1