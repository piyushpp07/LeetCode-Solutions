class MapSum {
public:
    unordered_map<string,int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int cnt = 0;
        for(auto i : mp)
        {
            string s = i.first;
            if(prefix.size()<=s.size()){
                bool ans = true;
                for(int j = 0;j<prefix.size();j++)
                {
                    if(prefix[j]!=s[j])
                        ans = false;
                }
                if(ans)
                    cnt+=i.second;
            }
        }
        return cnt;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */