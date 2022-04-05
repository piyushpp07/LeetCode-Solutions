#define lli long long int
class Solution {
private:
    bool isValid(vector<int>&v,int m,int mid)
    {   int prev = v[0],cnt = 1;
        for(int i= 0;i<v.size();i++)
        {
            if(v[i]-prev>=mid)
            {
                prev = v[i];
                cnt++;
            }
        }
        return cnt>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        lli st = 0,end = 1e9,ans=0;;
        sort(position.begin(),position.end());
        while(st<=end)
        {
            int mid = (st+end)/2;
            if(isValid(position,m,mid))
            {
               st = mid+1;
                ans = mid;
            }
            else {
                end = mid-1;
            }
        }
       return ans;
   }
};