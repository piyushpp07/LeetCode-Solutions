bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
class Solution
{
    public:
        int scheduleCourse(vector<vector < int>> &courses)
        {
            sort(courses.begin(), courses.end(), comp);
            priority_queue<int> pq;
            int sum = 0;
            for (auto i: courses)
            {
                sum += i[0];
                pq.push(i[0]);
                if (sum > i[1])
                {
                    int top = pq.top();
                    pq.pop();
                    sum -= top;
                }
            }
            return pq.size();
        }
};