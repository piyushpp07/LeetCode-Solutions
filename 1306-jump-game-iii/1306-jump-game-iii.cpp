class Solution
{  private:
      int vis[100001];
    public:
        bool canReach(vector<int> &arr, int start)
        {
            if(start>arr.size() || start < 0 || vis[start] ==1)
             return false;
            if (arr[start] == 0 )
            {
                return true;
            }
     
            vis[start] = 1;
            bool ans = false;
            int a = arr[start];
            if (a + start < arr.size())
                ans = ans || canReach(arr, a + start);
            if (start - a >= 0)
                ans = ans || canReach(arr, start - a);
            return ans;
        }
};