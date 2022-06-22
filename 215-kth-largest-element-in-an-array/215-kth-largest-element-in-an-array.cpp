bool comp(int a,int b)
{
        return a>b;
}
class Solution
{
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
            sort(nums.begin(), nums.end(),comp);
            return nums[k-1];
        }
};