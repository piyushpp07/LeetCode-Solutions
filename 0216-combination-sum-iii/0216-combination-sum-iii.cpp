class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k,int n,vector<int>&arr,int sum,int curr)
    {
        if(sum > n)
            return ;
        if(sum == n )
        {
            if(arr.size() == k)
            ans.push_back(arr);
            return ;
        }
        for(int i = curr + 1;i<=9;i++)
        {
            arr.push_back(i);
            solve(k,n,arr,sum + i,i);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        solve(k,n,arr,0,0);
        return ans;
    }
};