class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i] == 0)
            {   int j = i;
                while(j+1<n&&nums[j+1]!=0)
                {
                    nums[j] = nums[j+1];
                    j++;
                }
                nums[j] = 0;
                
            }
        }
    }
}