class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int  n = nums.size();
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            a.push_back(nums[nums[i]]);
        }
        return a;
    }
};