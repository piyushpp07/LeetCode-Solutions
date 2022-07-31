class NumArray {
public:
    vector<int> bit;
    vector<int> values;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.resize(n+1, 0);
        values.resize(n+1, 0);
        
        for(int i=0; i<n; i++) {
            update(i, nums[i]);
            values[i] = nums[i];
        }
    }
    
    void update(int index, int val) {
        for(int i=index+1; i<=n; i+=(i&(-i))) {
            bit[i] += (val - values[index]);
        }
        values[index] = val;
    }
    
    int sum(int index) {
        int ans = 0;
        for(int i=index; i>0; i-=(i&(-i))) {
            ans += bit[i];
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
    }
};