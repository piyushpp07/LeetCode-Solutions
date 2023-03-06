class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto i : arr)
            mp[i]++;
        int i = 1;
        while(k)
        {
            if(mp.find(i)==mp.end())
                k--;
            i++;
        }
        return i-1;
    }
};