class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int currsum = 0,res = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
                currsum+=nums[i];
                if(currsum == k)res++;
                if(mp.find(currsum - k)!=mp.end())
                {
                        res+=mp[currsum-k];
                }
                mp[currsum]++;
        }
        return res;
    }
};