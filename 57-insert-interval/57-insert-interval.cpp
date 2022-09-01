class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>arr;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        for(int i = 0;i<n;i++)
        {
            int c_s = intervals[i][0];
            int c_e = intervals[i][1];
            while(i+1<n && c_e >= intervals[i+1][0])
            {                            
                i++;
                c_e = max(c_e,intervals[i][1]);
            }
            arr.push_back({c_s,c_e});
        }
        return arr;
    }
};