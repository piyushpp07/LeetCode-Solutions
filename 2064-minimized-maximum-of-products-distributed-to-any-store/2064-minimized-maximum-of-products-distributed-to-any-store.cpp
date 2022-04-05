class Solution {
public:
	int minimizedMaximum(int n, vector<int>& quantities) {
		int sum = 0, maxi = INT_MIN;
		for (int i = 0; i < quantities.size(); i++)
		{
			maxi = max(maxi, quantities[i]);
		}
		int lo = 1, hi = maxi, ans = 0;
		while (lo <= hi)
		{	int mid = (lo + hi) / 2;
			int cnt = 0;
			for (auto i : quantities)
			{
				cnt += i / mid;
				if (i % mid)cnt++;
			}
			if (cnt <= n)
			{
				ans = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		return ans;


	}
};