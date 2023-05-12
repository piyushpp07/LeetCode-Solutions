class Solution {
public:
    long long solve(vector<vector<int>>& questions,int idx,vector<long long int>&dp)
    {
        if(idx >= questions.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        long long a = questions[idx][0] + solve(questions,idx+questions[idx][1]+1,dp);
        long long b = solve(questions,idx + 1,dp);
        return dp[idx] =  max(a,b);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long int> dp(questions.size(),-1);
        return solve(questions,0,dp);
    }
};