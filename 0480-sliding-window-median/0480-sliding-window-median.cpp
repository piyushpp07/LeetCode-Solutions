class Solution {
public:
    double median(multiset<double>&data, int n)
    {
        double median;
        auto iter = data.cbegin();
        advance(iter, n / 2);  // iterator pointing to middle of the window
        if (n % 2 == 0) //if window if even sized then 
        {
            const auto iter2 = iter--;
            median = double(*iter + *iter2) / 2;  
        }
        else   // when window is odd size
        {
            median = *iter;
        }
        return median;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>v;  // ans array
        int i =0,j =0,n = nums.size(); // sliding window variables 
        multiset<double>ms;
        for(;j<k;j++)
            ms.insert(nums[j]);    // adding k elements to window 
        if(n == k)
            return {median(ms,k)};   // if window == k we will return only one median
        while(j<n)   // sliding window 
        {
            if(j-i<k)  // expanding till k
            {
                ms.insert(nums[j]);
                j++;
            }
            if(j-i == k)   //if window size is same as k then we will find median
            {
                double d = median(ms,k);
                v.push_back(d);
                auto lb = ms.lower_bound(nums[i++]); //shrinking window size
                ms.erase(lb);
            }
        }
        return v;
    }
};