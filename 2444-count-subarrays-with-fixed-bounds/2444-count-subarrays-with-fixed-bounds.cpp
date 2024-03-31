using lli = long long int; 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long ans = 0;
        int start = 0;
        int n = nums.size();
        int minInd = -1, maxInd = -1;
        for (int i=0; i<n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minInd = -1;
                maxInd = -1;
                start = i+1;
            }
            if (nums[i] == minK) minInd = i;
            if (nums[i] == maxK) maxInd = i;
            ans += max(0, min(minInd, maxInd)-start+1);
        }
        return ans;
    }
};
