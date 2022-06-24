class Solution
{
    public:
        bool isPossible(vector<int> &target)
        {
            long long int sum = 0, a = 0;
            priority_queue < long long int > pq(target.begin(), target.end());
            for (auto i: target)
                sum += i;
            while (true)
            {
                a = pq.top();
                pq.pop();
                sum -= a;
                if (a == 1 || sum == 1)
                    return true;
                else if (a < sum || sum == 0 || a % sum == 0)
                    return false;
                a %= sum;
                sum += a;
                pq.push(a);
            }
        }
};