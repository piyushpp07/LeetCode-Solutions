class Solution {
public:
    double average(vector<int>& salary) {
        double mini = *min_element(salary.begin(),salary.end());
        double maxi = *max_element(salary.begin(),salary.end());
        double ans = 0,cnt = 0;
        for(int i = 0;i<salary.size();i++)
        {
            if(salary[i] == mini || salary[i] == maxi)
                continue;
            else 
            {
                cnt++;
                ans += salary[i];
            }
        }
        return (ans)/cnt;
    }
};