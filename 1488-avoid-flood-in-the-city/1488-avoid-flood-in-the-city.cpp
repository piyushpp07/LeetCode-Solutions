class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int>ans;
        unordered_map<int,int>mp;
        set<int>st;
        for(int i =0 ;i<rains.size();i++)
        {
            if(rains[i] == 0)
            {
                st.insert(i);
                ans.push_back(1);
            }
            else {
                int lake = rains[i];
                if(mp.find(lake)!=mp.end())
                {
                    auto it = st.lower_bound(mp[lake]);
                    if(it == st.end())
                        return {};
                    int idx = *it;
                    ans[idx] = lake;
                    st.erase(idx);
                }
                mp[lake] = i;
                ans.push_back(-1);
            }
        }
        return ans;
    }
};