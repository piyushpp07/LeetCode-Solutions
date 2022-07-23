using pp = pair<int, int> ;
class Solution
{
    public:
        void merge(int lo, int mid, int hi, vector<int> &count, vector<pp> &arr)
        {
            int i = lo, j = mid + 1, k = 0;
            vector<pp> temp(hi - lo + 1);
            while (i <= mid && j <= hi)
            {
                if (arr[i].first > arr[j].first)
                {
                    temp[k++] = arr[i];
                    count[arr[i].second] += (hi - j + 1);
                    i++;
                }
                else
                {
                    temp[k++] = arr[j];
                    j++;
                }
            }
            while (i <= mid)
            {
                temp[k++] = arr[i++];
            }
            while (j <= hi)
            {
                temp[k++] = arr[j++];
            }
            for (int i = lo; i <= hi; i++)
            {
                arr[i] = temp[i - lo];
            }
            return;
        }
    void mergesort(int lo, int hi, vector<int> &count, vector<pp> &arr)
    {
        if (lo < hi)
        {
            int mid = (lo + hi) / 2;
            mergesort(lo, mid, count, arr);
            mergesort(mid + 1, hi, count, arr);
            merge(lo, mid, hi, count, arr);
        }
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pp> arr(n);
       for(int i=0;i<n;i++)
        {
            arr[i]={nums[i] , i};
        }
        mergesort(0, n - 1, count, arr);
        return count;
    }
};