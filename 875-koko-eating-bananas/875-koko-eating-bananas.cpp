class Solution {
    private:
    bool check(vector<int>&piles,int no,int h)
    {
        int hrs=0;
        for(auto i : piles)
        {   int z=i/no;
            hrs+=z;
            if(i%no!=0)
                hrs++;
        }
        return hrs<=h;
    }
        
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int lo=1;
        int hi=piles[piles.size()-1];
        while(lo<=hi)
        {
            int mid = hi-(hi-lo)/2;
            if(check(piles,mid,h))
               hi=mid-1;
            else lo=mid+1;
        }
         return lo;
    }
               
};