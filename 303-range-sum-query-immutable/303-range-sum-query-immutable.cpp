class NumArray {
public:
    vector<int>p;
    NumArray(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++)
            nums[i] = nums[i-1]+nums[i];
        p = nums;
    }
    
    int sumRange(int left, int right) {
        int no = 0;
        if(left>0)
            no = p[left-1];
        return p[right]-no;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */