class Solution
{
    public:
        int nextGreaterElement(int n)
        {
            string str = to_string(n);
            int no = str.size();
            if (n < 10)
                return -1;
            int i = no - 2;
            while (i >= 0 && str[i] >= str[i + 1])
                i--;
            if (i == -1)
                return -1;
            int j = no - 1;
            while (j>i && str[j] <= str[i])
                j--;
            swap(str[i], str[j]);
            reverse(str.begin()+i+1, str.end());
            long long int l = stoll(str);
            return l>INT_MAX?-1:l;
        }
};