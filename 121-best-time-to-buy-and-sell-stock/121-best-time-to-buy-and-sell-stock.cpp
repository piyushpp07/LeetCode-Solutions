class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int mini = 1e9;
            int maxans = 0;
            for (int i = 0; i < prices.size(); i++)
            {
                mini = min(prices[i],mini);
                maxans = max(maxans,prices[i]-mini);
            }
            return maxans;
        }
};