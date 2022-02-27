class Solution {
private:
    int bsf(vector<int>&nums,int target)
    {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                hi = mid - 1;
            if(nums[mid]<target)
                lo = mid +1;
        }
        return lo;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return bsf(nums,target);
    }
};