using lli = long long int;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& s) {
        lli n = s.size(),ans = 0;
        lli co = 0;
        for(int i =0 ;i<n;i++)
        {
            if(s[i] == 0)
                co++;
            else
            {
                ans = ans + (co * (co+ 1))/2;
                co = 0;
            }
        }
        ans += (co * (co + 1))/2;
        return ans;
    }
};