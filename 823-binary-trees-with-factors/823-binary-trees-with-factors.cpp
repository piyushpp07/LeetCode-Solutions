using lli = long long int;
lli mod = 1e9 + 7;
class Solution
{
    public:
        unordered_map<int, int> mp;
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        unordered_map<lli, lli> mp;
        int n = arr.size();
        lli a = 0;
        sort(arr.begin(),arr.end());
        for (int i = 0; i < n; i++)
        {
            int c_a = 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j])
                    continue;

                lli num1 = arr[j];
                lli num2 = arr[i] / arr[j];
                c_a = (c_a + mp[num1] *mp[num2] % mod) % mod;
            }
            mp[arr[i]] = c_a;
            a = (a + c_a) % mod;
        }
        return a;
    }
};