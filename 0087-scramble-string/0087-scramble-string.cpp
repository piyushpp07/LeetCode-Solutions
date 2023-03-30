class Solution {
public:
    bool ans = false;
    map<string,bool>mp;
    bool solve(string s1,string s2)
    {
        if(s1 == s2)
            return true;
        string ll = s1;
        string ss = s2;
        sort(ll.begin(),ll.end());
        sort(ss.begin(),ss.end());
        if(ss != ll)
            return false;
        string key = s1+"-1"+s2;
        if(mp.count(key))
            return mp[key];
        int n = s1.size();
        for(int i = 1;i<n;i++)
        {
            if(solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i,n-i),s2.substr(i,n-i)))
                return mp[key] =  true;
            if(solve(s1.substr(0,i),s2.substr(n-i,i))&&solve(s1.substr(i,n-i),s2.substr(0,n-i)))
                return mp[key] =  true;
        }
        
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
    
        return solve(s1,s2);
    }
};