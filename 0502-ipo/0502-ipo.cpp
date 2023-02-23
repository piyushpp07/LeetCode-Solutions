bool comp(vector<int>&a,vector<int>&b)
{
    if(a[0] == b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>>v;
        for(int i =0 ;i<capital.size();i++)
        {
            v.push_back({capital[i],profits[i]});
        }
        int ans = 0;
        sort(v.begin(),v.end(),comp);
        priority_queue<int>pq;
        int n = profits.size();
        int i = 0;
        while (k--) {

          while (i < n && v[i][0] <= w) {
                pq.push(v[i++][1]);
        }
        if (pq.empty())
            break;
        w += pq.top();
        pq.pop();
        }
         return w;
    }
};