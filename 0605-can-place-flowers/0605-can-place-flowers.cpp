class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int i = 0,cnt =0,k = arr.size();
        while(i<k)
        {
            if(arr[i] == 0 )
            {
                if(  i-1 == -1 || (i - 1 >=0 && arr[i-1] == 0)){
                    if(i + 1 == k|| (i + 1 < k && arr[i + 1] == 0) )
                    {
                        cnt++;
                        arr[i] = 1;
                    }
                }
            } 
            i++;
        }
        return cnt>=n;
    }
};