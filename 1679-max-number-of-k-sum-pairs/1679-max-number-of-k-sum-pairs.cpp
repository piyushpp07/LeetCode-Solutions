class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt = 0;
        for(auto i : nums)
        {
                int comp = k - i;
                if(mp[comp]>0){cnt++,mp[comp]--;}
                else mp[i]++;
        }
        return cnt;
    }
};