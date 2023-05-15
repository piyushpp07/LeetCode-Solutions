class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ele = *max_element(nums.begin(),nums.end());
        return k * ele + ((k)*(k-1))/2;
    }
};