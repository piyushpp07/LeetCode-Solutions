class Solution {
public:
    set<vector<int>>st;
    void solve(vector<int>nums,vector<int>v,int idx)
    {
        if(idx == nums.size())
        {
            sort(v.begin(),v.end());
            st.insert(v);
            return ;
        }
        v.push_back(nums[idx]);
        solve(nums,v,idx+1);
        v.pop_back();
        solve(nums,v,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        solve(nums,v,0);
        vector<vector<int>>ans;
        for(auto i : st)
            ans.push_back(i);
        return ans; 
    }
};