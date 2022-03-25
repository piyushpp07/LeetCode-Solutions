class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = 0,i=1;
        for(auto num: nums)
        {
            a = a^num^i;
            i++;
        }
        return a;

        
    }
};