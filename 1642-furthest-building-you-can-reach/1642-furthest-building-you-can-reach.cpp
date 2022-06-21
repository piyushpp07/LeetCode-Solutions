class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        for(int i = 1;i<heights.size();i++)
        {
             int req = heights[i]-heights[i-1];
             if(req > 0)
             {
                 pq.push(req);
                 bricks -= req;
                 if(bricks<0)
                 {
                         bricks += pq.top();
                         --ladders;
                         pq.pop();
                         if(bricks<0||ladders<0)
                                 return i - 1;
                 }
             }
                
        }
            return heights.size()-1;
    }
};