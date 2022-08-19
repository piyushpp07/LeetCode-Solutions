class Solution {
public:
    bool isPossible(vector<int>& nums) {
           
    if(nums.size() < 3)
        return false;
    
    unordered_map<int, int> mp;
    for(int x: nums)
        mp[x]++;
    
    for(auto val: nums) {
        
        int curr = val;
        int fq = mp[curr];
        
        if(fq == 0)
            continue;
        
        int count = 0;
        while(mp[curr] >= fq) {
            
            fq = max(fq, mp[curr]);
            mp[curr]--;
            curr++;
            count++;
        }
        
        if(count < 3)
            return false;
    }
    
    return true;
    }
};