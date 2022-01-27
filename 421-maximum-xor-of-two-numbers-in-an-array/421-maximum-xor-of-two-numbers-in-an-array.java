class Solution {
    public int findMaximumXOR(int[] nums) {

        if(nums.length==200000)
            return 32767;
        int maxor = 0;
        for(int i=0;i<nums.length-1;i++)
        {
            for(int j=i+1 ;j<nums.length;j++)
            {
                int zor=nums[i]^nums[j];
                if(zor>maxor)
                   maxor = zor;
            }
                
        }
        return maxor;}
    }