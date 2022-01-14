class Solution {
public:
     void swap(vector<int>&nums,int start , int end )
    {
        int temp = nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
    }
   void reverse(vector<int>&nums,int start , int end )
    {
        while(start<=end)
        {
            swap(nums,start,end);
            start++;
            end--;
        }
    }
    void rotate(vector<int>&nums, int k) {
        int n = nums.size();
        k=k%n;
        if(k<0)
            k=k+n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};