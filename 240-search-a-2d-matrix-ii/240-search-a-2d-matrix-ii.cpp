class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int x = 0 , y = matrix[0].size()-1  , ans = 0;
		while (x < matrix.size() && y >= 0)
		{
			if (matrix[x][y] == target)
			{
				ans = 1;
				break;
			}
			else if (matrix[x][y] > target)
				y--;
			else if (matrix[x][y] < target)
				x++;
		}
		if (ans == 1)
			return true;
		else
			return false;
	}
};