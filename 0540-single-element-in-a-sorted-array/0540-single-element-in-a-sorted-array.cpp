class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int no = 0;
        for(auto i : nums)
            no = no ^ i;
        return no;
    }
};