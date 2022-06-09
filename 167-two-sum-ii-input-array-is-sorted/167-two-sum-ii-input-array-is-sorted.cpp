class Solution
{
    int binary(vector<int> &numbers, int req)
    {
        int s = 0, e = numbers.size() - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (numbers[mid] == req)
                return mid;
            else if (numbers[mid] > req)
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return -1;
    }
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            vector<int> v;
            for (int i = 0; i < numbers.size(); i++)
            {
                int a = target - numbers[i];
                int idx = binary(numbers, a);
                if (idx == -1 || idx == i)
                    continue;
                else
                {
                    v.push_back(i + 1);
                    v.push_back(idx + 1);
                    break;
                }
            }
            sort(v.begin(), v.end());
            return v;
        }
};