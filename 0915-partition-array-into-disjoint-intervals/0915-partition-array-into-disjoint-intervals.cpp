class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,0),right(n,0);
        left[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            left[i] = max(nums[i],left[i-1]);
        }
        right[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--)
        {
            right[i] = min(nums[i],right[i+1]);
        }
        for(int i = 1;i<n;i++)
        {
            if(left[i-1]<=right[i])
                return i;
        }
        return -1;
    }
};