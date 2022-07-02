int mod = 1e9 + 7;
class Solution
{
    public:
        int maxArea(int h, int w, vector<int> &hCuts, vector<int> &vCuts)
        {
            int hs = hCuts.size();
            int vs = vCuts.size();
            int hmax = 0;
            int vmax = 0;
            sort(hCuts.begin(), hCuts.end());
            sort(vCuts.begin(), vCuts.end());

            hmax = hCuts[0];
            hmax = max(hmax, h - hCuts[hs - 1]);

            vmax = vCuts[0];
            vmax = max(vmax, w - vCuts[vs - 1]);

            for (int i = 1; i < hs; i++)
                hmax = max(hmax, hCuts[i] - hCuts[i - 1]);

            for (int i = 1; i < vs; i++)
                vmax = max(vmax, vCuts[i] - vCuts[i - 1]);

            return (long) hmax *vmax % (mod);
        }
};