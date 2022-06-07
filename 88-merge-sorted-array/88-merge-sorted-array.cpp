class Solution
{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
            int j = 0;
            for (int i = m; i < nums1.size(); i++)
                nums1[i] = nums2[j++];
            int z = nums1.size();
            for (int i = 0; i < z-1; i++)
            {
                for (int j = i+1; j < z; j++)
                {
                    if (nums1[i] > nums1[j])
                    {
                        swap(nums1[i], nums1[j]);
                    }
                }
            }
        }
};