class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size();
		vector<int>dup;
		for (int i : nums)
		{
			dup.push_back(i);
		}
		sort(nums.begin(), nums.end());
		int i = 0, j = n - 1;
		while(i<n&&nums[i]==dup[i])
                        i++;
                while(j>0&&nums[j]==dup[j])
                        j--;

                if(j>i)
                        return j-i+1;
                else
                return 0;

	}
};