using lli = long long int;
class Solution {
public:
    void primeFactors(int n,unordered_map<int,int>&mp)
    {
       
        for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
            if (n % i == 0) {
                mp[i]++;
                while(n % i == 0)
                    n /= i;
            }
        if (n > 1)
           mp[n]++;
    }

    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>left,right;
        for(int i : nums)
        {
            primeFactors(i,right);
        }
        int idx  = 0;
        for(int k  = 0; k < n-1; k++)
        {
            int i = nums[k];
            primeFactors(i,left);
            bool ans  = true;
            for(auto j : left)
            {
                if(right.find(j.first)!=right.end()&&right[j.first] != j.second)
                {
                    ans = false;
                    break;
                }
            }
            if(ans)
                return idx;
            idx++;
        }
        return -1;
        
    }
};