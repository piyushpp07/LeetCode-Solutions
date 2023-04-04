class Solution {
public:
    int partitionString(string s) {
        map<char,int>mp;
        int cnt =1;
        for(auto i:s)
        {
            if(mp.find(i) != mp.end())
            {
                map<char,int>mp1;
                mp = mp1;
                cnt++;
            }
            mp[i]++;
        }
        return cnt;
        
    }
};