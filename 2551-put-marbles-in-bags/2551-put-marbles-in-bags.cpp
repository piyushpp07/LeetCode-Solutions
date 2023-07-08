using lli = long long int;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == 1 || weights.size() == k)
            return 0;
        lli mini = 0,maxi = 0;
        vector<long long int>sum1,sum2;
        for(int i = 0;i<weights.size()-1;i++)
        {
            weights[i] += weights[i+1];
            sum1.push_back(weights[i]);
            sum2.push_back(weights[i]);
        }
        sort(sum1.begin(),sum1.end());
        sort(sum2.rbegin(),sum2.rend());
        for(int i = 0;i<k-1;i++){
            maxi += sum2[i];
            mini += sum1[i];
        }
        return maxi - mini;

    }
};