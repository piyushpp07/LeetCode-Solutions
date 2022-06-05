   bool comp(int a, int b)
   {
       return a > b;
   }
   class Solution
   {
       public:
           int partitionArray(vector<int> &nums, int k)
           {
               sort(nums.begin(), nums.end(), comp);
               int cnt = 1;
               int ih = 0;
               for (int i = 0; i < nums.size(); i++)
               {
                   if (nums[ih] - nums[i] > k)
                   {
                       cnt++;
                       ih = i;
                   }
               }
               return cnt;
           }
   };