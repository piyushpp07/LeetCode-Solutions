class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int>v(nums.size(), 0);
		int n = nums.size();
		stack<int>st;
		int i = 0;
		for (int i = 0; i < n; i++)
		{
	
				int j = (i + 1) % n;
				while (j != i && nums[j] <= nums[i])
				{
					j = (j + 1) % n;
				}
				if (j == i)
					v[i] = -1;
				else
				{
					v[i] = nums[j];
				
				}

			

		}
		return v;
	}
};