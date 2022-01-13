class Solution {
int fi(vector<int>&nums,int target)
{
    int hi = nums.size()-1;
    int lo = 0;
    int first= -1;
    while(hi>=lo)
    {
        int mid = (hi+lo)/2;
        if(nums[mid]==target)
        {
            first = mid;
            hi = mid-1;
        }
       else if(nums[mid]<target)
        {
            lo = lo+1;
        }
        else 
            hi = mid -1;
    }
    return first;
    
}
int li(vector<int>&nums,int target)
{
    int hi = nums.size()-1;
    int lo = 0;
    int last= -1;
    while(hi>=lo)
    {
        int mid = (hi+lo)/2;
        if(nums[mid]==target)
        {
            last = mid;
            lo = mid+1;
        }
        else if(nums[mid]<target)
        {
            lo = lo+1;
        }
        else 
            hi = mid -1;
    }
    return last;
    
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int first = fi(nums,target);
        int last = li(nums,target);
        v.push_back(first);
        v.push_back(last);
        return v;
    }
};