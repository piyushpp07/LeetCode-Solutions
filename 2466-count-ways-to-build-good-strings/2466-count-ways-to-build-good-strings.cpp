using lli = long long int;
int mod = 1e9 + 7;

class Solution {
public:
    lli mp[100002];
    lli solve(int low,int high,int zero,int one, int idx)
    {
        if(idx > high)
            return 0;
        if(mp[idx]!=-1)
            return mp[idx];
        
        if(idx >= low &&  idx <= high)
        {
            //add zero
            lli a = solve(low,high,zero,one,idx + zero);
            // add one 
            lli b = solve(low,high,zero,one,idx + one);
            return mp[idx] = (a % mod + b % mod + 1 % mod )%mod;
            
        }

        lli a = solve(low,high,zero,one,idx + zero);
                // add one 
        lli b = solve(low,high,zero,one,idx + one);
        return mp[idx] = (a%mod + b%mod)%mod;
 

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        //1d dp 
        memset(mp,-1,sizeof mp);
        return solve(low,high,zero,one,0);
    }
};


// l - 3, h = 3 , zero = 1 ,one = 1
// at zero we have // add zero or not add zero or add zero and sub zero 
// at one we have 