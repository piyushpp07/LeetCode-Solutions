class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            int n = nums1.size();
            int m = nums2.size();
            vector<int> v;
            stack<int> s;
            for (int i = m - 1; i >= 0; i--)
            {
                if (s.size() == 0)
                    v.push_back(-1);
                else if (s.size() > 0 && s.top() >= nums2[i])
                {
                    v.push_back(s.top());
                }
                else if (s.size() > 0 && s.top() < nums2[i])
                {
                    while (s.size() > 0 && s.top() < nums2[i])
                    {
                        s.pop();
                    }
                    if (s.size() == 0)
                        v.push_back(-1);
                    else
                        v.push_back(s.top());
                }
                s.push(nums2[i]);
            }
            reverse(v.begin(), v.end());
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (nums1[i] == nums2[j])
                    {
                        nums1[i] = v[j];
                        break;
                    }
                }
            }
            return nums1;
        }
};