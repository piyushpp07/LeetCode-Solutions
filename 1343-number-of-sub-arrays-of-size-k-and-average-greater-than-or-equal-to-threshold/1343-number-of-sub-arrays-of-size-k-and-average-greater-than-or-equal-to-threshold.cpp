class Solution
{
    public:
        int numOfSubarrays(vector<int> &arr, int k, int threshold)
        {
            int cnt = 0;
            int i = 0, j = 0, n = arr.size();
            int sum = 0;
            while (j < n)
            {
                if (j >= k)
                {
                    sum += arr[j++];
                }
                while (j < k)
                {
                    sum += arr[j++];
                }

                if (sum / k >= threshold)
                    cnt++;
                sum -= arr[i];

                i++;
            }
            return cnt;
        }
};