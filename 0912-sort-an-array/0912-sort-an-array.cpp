class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        for(auto i : nums)
        {
            pq.push(i);
        }
        while(pq.size())
        {
            int ele = pq.top();
            pq.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};