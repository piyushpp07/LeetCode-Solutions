class Solution {
public:
    double median(multiset<double>&data, int n)
    {
        double median;
        auto iter = data.cbegin();
        advance(iter, n / 2);

        // Middle or average of two middle values
        if (n % 2 == 0)
        {
            const auto iter2 = iter--;
            median = double(*iter + *iter2) / 2;    // data[n/2 - 1] AND data[n/2]
        }
        else
        {
            median = *iter;
        }
        return median;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>v,q;
        int i =0,j =0,n = nums.size();
        multiset<double>ms;
        for(;j<k;j++)
            ms.insert(nums[j]);
        auto it = ms.begin();
        for(int p = 0;p<k/2;p++)
            it++;
        if(n == k)
            return {median(ms,k)};
        while(j<n)
        {
            if(j-i<k)
            {
                ms.insert(nums[j]);
                j++;
            }
            if(j-i == k)
            {
                double d = median(ms,k);
                v.push_back(d);
                auto lb = ms.lower_bound(nums[i]);
                ms.erase(lb);
                i++;
            }
        }
        return v;
    }
};