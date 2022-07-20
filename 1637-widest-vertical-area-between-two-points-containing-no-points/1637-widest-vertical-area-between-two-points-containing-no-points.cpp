bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else return a[1] < b[1];
}
class Solution
{
    public:
        int maxWidthOfVerticalArea(vector<vector < int>> &points)
        {
            sort(points.begin(), points.end(), comp);
            int area = 0;
            for (int i = 1; i < points.size(); i++)
            {
                area = max(area, points[i][0] - points[i - 1][0]);
            }
            return area;
        }
};