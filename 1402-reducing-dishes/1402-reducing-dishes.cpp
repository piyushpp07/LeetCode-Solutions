class Solution {
public:
    int solve(vector<int>&arr,int idx,int time,vector<vector<int>>&dp)
    {
        if(idx == arr.size())
            return 0;
        if(dp[idx][time]!=-1)
            return dp[idx][time];
        int a =0,b = 0;
        //select
        a = arr[idx]*time + solve(arr,idx+1,time+1,dp);
        //not select
        b = solve(arr,idx+1,time,dp);
        return dp[idx][time] = max(a,b);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        vector<vector<int>>dp(600,vector<int>(700,-1));
        sort(satisfaction.begin(),satisfaction.end());
        
        return max(0,solve(satisfaction,0,1,dp));
        
    }
};