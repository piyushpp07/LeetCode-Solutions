class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int i = 0, j = 0,n = nums.size();
        double sum = 0,ans = -1000000;
        while(j<n)
        {
            if(j>=k)
            {
                sum+=nums[j++];
            }
            while(j<k)
            {
                sum+=nums[j++];
            }
            double avg = double(sum / k);
            if(avg > ans)
                ans = avg;
            sum -= nums[i++];
        }
        return ans;
    }
};