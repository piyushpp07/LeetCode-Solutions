class Solution
{
    private:
        int a, b, c, d;
    bool solve(vector<int> &arr, int i)
    {
        if (i == arr.size())
        {
            if (a == 0 && b == 0 && c == 0 && d == 0) return true;
            return false;
        }
        bool ans = false;
        if (arr[i] <= a)
        {
            a -= arr[i];
            if (solve(arr, i + 1)) return true;
            a += arr[i];
        }
        if (arr[i] <= b)
        {
            b -= arr[i];
            if (solve(arr, i + 1)) return true;
            b += arr[i];
        }
        if (arr[i] <= c)
        {
            c -= arr[i];
            if (solve(arr, i + 1)) return true;
            c += arr[i];
        }
        if (arr[i] <= d)
        {
            d -= arr[i];
            if (solve(arr, i + 1)) return true;
            d += arr[i];
        }
        return false;
    }
    public:
        bool makesquare(vector<int> &ms)
        {
            if (ms.size() < 4) return false;
            int sum = 0;
            sort(ms.begin(), ms.end());
            for (auto i: ms)
                sum += i;
            if (sum % 4 != 0)
                return 0;
            reverse(ms.begin(), ms.end());
            a = sum / 4, b = sum / 4, c = sum / 4, d = sum / 4;
            return solve(ms, 0);
        }
};