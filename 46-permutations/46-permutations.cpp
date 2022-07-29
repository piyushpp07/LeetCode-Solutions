class Solution
{
    private:
        vector<vector < int>> ans;
    public:
        void solve(vector<int>&nums,int idx)
        {
            if(idx == nums.size())
            {
                ans.push_back(nums);
            }
            for(int i = idx;i<nums.size();i++)
            {
                swap(nums[idx],nums[i]);
                solve(nums,idx+1);
                swap(nums[idx],nums[i]);
            }
        }
            
        vector<vector < int>> permute(vector<int> &nums) {
            solve(nums,0);
            return ans;
        }
};