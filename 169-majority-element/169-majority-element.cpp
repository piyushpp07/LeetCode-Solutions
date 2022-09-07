class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto i : nums)
            mp[i]++;
        int maj = INT_MIN;
        int check = nums.size()/2;
        if(nums.size() % 2 != 0)
            check+=1;
            
        for(auto i : mp)
        {   
            if(i.second >= check)
                maj = i.first;
        }
        return maj;
    }
};