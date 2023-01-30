class Solution {
public:
    int countGoodSubstrings(string s) {
        map<char,int>mp;
        int i = 0,cnt = 0,j = 0,n = s.size();
        while(j<n)
        {
            if(j>=3)
            {
                mp[s[j++]]++;
            }
            while(j<3)
            {
                mp[s[j++]]++;
            }
            if(mp.size() == 3)
                cnt++;
            char ch = s[i++];
            mp[ch]--;
            if(mp[ch] == 0)
                mp.erase(ch);
            
            
        }
        return cnt;
    }
};