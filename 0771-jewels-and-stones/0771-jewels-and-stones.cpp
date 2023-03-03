class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        map<char,int>mp;
        for(auto i : jewels)
        {
            mp[i] = 1;
        }
        for(int i = 0;i<stones.size();i++)
        {
            if(mp.find(stones[i])!=mp.end())
                cnt++;
        }
        return cnt;
    }
};