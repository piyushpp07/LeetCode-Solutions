class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int last = n+1;
        int next = 0;
        int ans = INT_MIN;
        for(int i = 1 ;i <= n ; i++ )
        {
            if(seats[i-1]==1)
            {
                last = i;
                continue;
            }
            for(int j = i+1 ;j <= n;j++)
            {
                if(seats[j-1]==1)
                {
                    next = j; 
                    break;
                }
            }
            if(abs(i-last)>abs(i-next))
                ans = max(ans , abs(i-next));
            else ans = max(ans ,abs(i-last));
            
        }
        return ans ;
    }
};