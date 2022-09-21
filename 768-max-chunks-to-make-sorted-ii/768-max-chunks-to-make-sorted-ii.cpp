class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
         int n = arr.size();
        
         vector<int>rmin(n+1,0);
        
         int lmini = arr[n-1];
        
         rmin[n]=INT_MAX;
        
         for(int  i = n - 1;i>=0;i--)
         {
             
             lmini = min(lmini,arr[i]);
             rmin[i] = lmini;
         }
        
         int chunks = 0,curr_max  = 0;
        
         for(int i = 0;i<n;i++)
         {
             curr_max = max(arr[i],curr_max);
             if(curr_max<=rmin[i+1])
             {
                 chunks++;
                 curr_max = 0;
             }
         }
        return chunks;
    }
};