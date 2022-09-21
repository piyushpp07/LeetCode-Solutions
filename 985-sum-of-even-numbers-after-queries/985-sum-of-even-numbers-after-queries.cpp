class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        for(auto i : nums)
        {
            if(i%2 == 0)
            ans+=i;
        }
        vector<int>arr;
        for(int i = 0;i<queries.size();i++)
        {
            int no = queries[i][0];
            int idx = queries[i][1];
            if(nums[idx]%2 == 0)
            {
                if((nums[idx]+no)%2 == 0)
                {
                    nums[idx] = nums[idx]+no;
                    ans+=no;
                }
                else{
                    ans -= nums[idx];
                    nums[idx] = nums[idx]+no;
                }
            }
            else{
                if((nums[idx]+no)%2 == 0)
                {
                    nums[idx] = nums[idx]+no;
                    ans= ans + nums[idx];
                }
                else{
                   nums[idx] = nums[idx]+no; 
                }
            }
            arr.push_back(ans);
        }
        return arr;
    }
};