class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		bool ans = false;
		int i = 0, j = matrix[0].size() - 1;
		int q = matrix.size();
		if (target < matrix[0][0] && target > matrix[q - 1][j])
			return false;
		else {
			while (i <= q - 1 && j >= 0)
			{
				if (matrix[i][j] == target)
					return true;
				else if (matrix[i][j] > target)
					j--;
				else
					i++;
			}
		}
		return false;

	}
};
