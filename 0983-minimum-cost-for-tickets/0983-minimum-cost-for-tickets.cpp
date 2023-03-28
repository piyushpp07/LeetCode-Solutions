class Solution {
public:

    int solve(int i,vector<int>&days,vector<int>&costs,int tillday,vector<vector<int>>&dp)
    {
        if(tillday<=1)
        {
            return 0; 
        }
     if(i == -1)
            return 0;
        if(dp[i][tillday]!=-1)
            return dp[i][tillday];

        int sum = 0;
        if(days[i] >= tillday)
        {
            sum += solve(i-1,days,costs,tillday,dp);
        }
        else {
            int a =0,b =0,c = 0;
            a = costs[0] + solve(i - 1,days,costs,days[i],dp);
            b = costs[1] + solve(i - 1,days,costs,days[i] - 6 >= 1 ? days[i]-6 : 1,dp);
            c = costs[2] + solve(i - 1,days,costs, days[i] - 29 >=1 ? days[i] - 29 : 1,dp);
            sum += min({a,b,c});
        }
        return dp[i][tillday] = sum;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>>dp(367,vector<int>(367,-1));
    
        return solve(n-1,days,costs,days[n-1]+1,dp);
    }
};