class Solution {
private:
	int maxnum = 0;
	string ans = "";
	string solve(vector<int>&cost, int target,   unordered_map<int,string>&dp)
	{
	   if(target<0)
                   return "0";
           if(target == 0)
                   return "";
           if(dp.count(target)>0)
                   return dp[target];
           string res = "0",curr;
           for(int i = 0;i<cost.size();i++)
           {
                   curr = solve(cost,target-cost[i],dp);
                   if(curr=="0")       // skip if can't solve sub-problem
                   continue;
                   curr = to_string(i+1)+curr;
                   if(res.size()<=curr.size())
                           res = curr;
           }
           return dp[target] = res;
	}
public:
	string largestNumber(vector<int>& cost, int target) {
		  unordered_map<int,string>dp;
		return solve(cost, target, dp);
	}
};