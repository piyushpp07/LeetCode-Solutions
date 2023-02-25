class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i = 0;i<prices.size();i++)
        {
            ans = max(prices[i]-mini,ans);
            mini = min(mini,prices[i]);
        }
        return ans;
    }
};