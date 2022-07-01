bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}
class Solution
{

    public:
        int maximumUnits(vector<vector < int>> &boxTypes, int truckSize)
        {
            sort(boxTypes.begin(), boxTypes.end(), comp);
            int i = 0, ans = 0;

            for (int i = 0; i < boxTypes.size(); i++)
            {
                int box = boxTypes[i][0];
                if (truckSize <= box && truckSize > 0)
                {
                    ans += truckSize *boxTypes[i][1];
                    break;
                }
                else
                {
                    ans += box *boxTypes[i][1];
                    truckSize = truckSize - box;
                }
            }
            return ans;
        }
};