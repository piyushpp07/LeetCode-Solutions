class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int>sortedmap(1001,0);

        for(int i=0;i<n;i++)
        {
            sortedmap[trips[i][1]]+=trips[i][0];
            sortedmap[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<1001;i++)
        {
            capacity-=sortedmap[i];
            if(capacity<0)
                return false;
        }
        return true;
    
    }
};