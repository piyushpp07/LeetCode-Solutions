class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0,j = 0,ans = 0,n = nums.size();
        int zero  = 0 , one = 0;
        while(j<n)
        {
            if(nums[j] == 1)
                one++;
            else
                zero++;
            while(zero != 0)
            {
                if(nums[i]==0)
                    zero--;
                i++;
            }
            ans = max(ans,j- i +1);
            j++;
        }
        return ans;
    }
};