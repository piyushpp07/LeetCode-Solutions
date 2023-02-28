class Solution {
public:
    double median(vector<double>&q, int k)
    {
        double x;
        if(k%2 == 0)
             x=(double)(q[k/2]+q[k/2-1])/2;
        else
             x=(double)q[k/2];
        return x;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>v,q;
        int i =0,j =0,n = nums.size();
        for(;j<k;j++)
            q.push_back(nums[j]);
        sort(q.begin(),q.end());
        if(n == k)
            return {median(q,k)};
        while(j<n)
        {
            if(j-i<k)
            {
                int ub = upper_bound(q.begin(),q.end(),nums[j])-q.begin();
                q.insert(q.begin()+ub,nums[j]);
                j++;
            }
            if(j-i == k)
            {
                double d = median(q,k);
                v.push_back(d);
                int init_pos = lower_bound(q.begin(), q.end(), nums[i])-q.begin();
                q.erase(q.begin()+init_pos);
                i++;
            }
        }
        return v;
    }
};