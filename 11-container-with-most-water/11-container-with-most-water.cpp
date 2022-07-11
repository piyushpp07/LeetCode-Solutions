class Solution
{
    public:
        int maxArea(vector<int> &h)
        {
            int n = h.size(), ans = 0;
            int l = 0, r = n - 1;
            while (l < r)
            {
                int q = abs(r - l) *min(h[l], h[r]);
                ans = max(q, ans);
                if (h[l] < h[r])
                    l++;
                else if (h[l] > h[r])
                    r--;
                else
                    l++, r--;
            }
            return ans;
        }
};