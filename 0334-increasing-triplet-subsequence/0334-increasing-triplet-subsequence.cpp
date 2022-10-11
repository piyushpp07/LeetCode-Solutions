class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
//         int n=nums.size();
//         // unordered_map<int,int> m;
//         // for(int i=0; i<n; i++){
//         //     m.insert{nums[i],i};
//         // }
//         vector<pair<int,int>> v;
//         for(int i=0; i<n; i++){
//             v.push_back({nums[i],i});
//         }
        
//         // for(int i=0; i<n-2; i++){
//         //     for(int j=i+1; j<n-1; j++){
//         //         for(int k=i+2; k<n; k++){
//         //             if(nums[i]<nums[j] and nums[j]<nums[k] and i<j and j<k) return true;
//         //         }
//         //     }
//         // }
//         // return false;
        int n = nums.size();
        vector<int>lis;
        for(int i = 0;i<n;i++)
        {
            if(lis.size() == 0)
                lis.push_back(nums[i]);
            else{
                auto it=lower_bound(lis.begin(),lis.end(),nums[i]);
                if(it==lis.end()) lis.push_back(nums[i]);
                else *it=nums[i];
            }
        }
        if(lis.size()>=3)
            return true;
        return false;
        
        
        
    }
};