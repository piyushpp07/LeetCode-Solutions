class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
                priority_queue<int>pq;
        int mini = INT_MAX;
        for(int i  : nums){
            if(i%2)i = i  * 2;
            mini = min(mini,i);
            pq.push(i);
        }
        int diff = INT_MAX;
        while(pq.top()%2 == 0)
        {
            int no = pq.top();
            pq.pop();
            diff = min(diff,no - mini);
            mini = min(mini,no/2);
            pq.push(no/2);
        }
        return min(diff,pq.top()-mini);
    }
};