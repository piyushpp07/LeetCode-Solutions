class Solution {
public:
    vector<int>v;
    Solution(vector<int>& nums) {
        for(auto i : nums)
        {
            v.push_back(i);
        }
    }
    
    int pick(int target) {
        int ans=0;
        while(1)
        {   
            int ran= rand()%v.size();
            if(v[ran]==target)
            {
             ans=ran;
             break;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */