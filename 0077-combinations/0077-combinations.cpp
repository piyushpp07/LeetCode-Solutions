class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int> &arr,int idx,vector<int> &v,int k)
    {
        if(idx == arr.size() && v.size() != k)
        {   
                return ;
        }
        if(idx == arr.size() && v.size() == k)
        {   
                ans.push_back(v);
                return ;
        }
        
        
        v.push_back(arr[idx]);
        solve(arr,idx+1,v,k);
        v.pop_back();
        solve(arr,idx+1,v,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        vector<int>v;
        for(int i = 1;i<=n;i++)
            arr.push_back(i);
        solve(arr,0,v,k);
        return ans;
    }
};