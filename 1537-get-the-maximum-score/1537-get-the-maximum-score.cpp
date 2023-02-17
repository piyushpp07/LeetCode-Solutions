int mod = 1e9 + 7;
using  lli  = long long int;
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0,j = 0;
        lli a = 0,b = 0;
        lli ans =0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j])
            {
                a += nums1[i++]; 
            }
            else if(nums2[j]<nums1[i])
            {
                b += nums2[j++];
            }
            else{
                ans += (max(a,b)+nums1[i])%mod;
                i++,j++;
                a = 0,b = 0;
            }
        }
        while(i<nums1.size()) a += nums1[i++];
        while(j<nums2.size()) b += nums2[j++];
        ans = (ans + max(a , b))%mod;
        return ans;
    }
};